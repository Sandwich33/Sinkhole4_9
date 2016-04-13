package com.inu.sandwich.sinkhole.activity;

import android.content.ClipData;
import android.content.ClipDescription;
import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.graphics.Point;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.os.Vibrator;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.Toast;

import com.inu.sandwich.sinkhole.R;
import com.inu.sandwich.sinkhole.view.HpInfoView;
import com.inu.sandwich.sinkhole.view.MinimapView;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by 0xFF00FF00 on 2016-04-02.
 */
public class TacticalActivity extends FullscreenActivity{
    private Context mContext;
    private MinimapView mapView;
    private LinearLayout ll_info;

    private HashMap<String,HpInfoView> infoViews;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_tactical);
        super.mContentView = findViewById(R.id.fullscreen_content);
        mContext = this;
        FrameLayout fl_map = (FrameLayout)findViewById(R.id.fl_map);
        ll_info = (LinearLayout)findViewById(R.id.ll_info);

        mapView = new MinimapView(this,v_handler);
        fl_map.addView(mapView);
        tcp.setHandler(handler);
        tcp.sendMessage("get;startInfo");
    }

    public void onStartDrone(View v){
        //tcp.sendMessage("set;Drone");
    }

    public void onFindMe(View v){
        mapView.setCameraKeyPlayer();
    }

    public void onSetAll(View v){
        Toast.makeText(this,"모두 나를 따라오라.!",Toast.LENGTH_SHORT).show();
        tcp.sendMessage("set;setall");
    }

    public Handler v_handler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            if( msg != null && msg.obj != null){
                switch (msg.what){
                    case 0: // Tab
                        mapView.setCameraKey(msg.obj.toString());
                        break;
                    case 1: // Long
                        HpInfoView hpInfoView = infoViews.get(msg.obj.toString());
                        Log.d("DragClickListener","Start : "+msg.obj.toString());
                        ClipData.Item item = new ClipData.Item(msg.obj.toString());//(CharSequence) view.getTag());
                        String[] mimeTypes = { ClipDescription.MIMETYPE_TEXT_PLAIN };
                        ClipData data = new ClipData(msg.obj.toString(),mimeTypes, item);
                        View.DragShadowBuilder shadowBuilder = new View.DragShadowBuilder(hpInfoView);

                        hpInfoView.startDrag(data, // data to be dragged
                                shadowBuilder,//shadowBuilder, // drag shadow
                                hpInfoView, // 드래그 드랍할  Vew
                                0 // 필요없은 플래그
                        );
                        break;
                    case 2: // Double
                        tcp.sendMessage("fol;"+msg.obj.toString());
                        break;
                    case 3: // Drop
                        float x = msg.arg1/1000.0f;
                        float y = msg.arg2/1000.0f;
                        tcp.sendMessage("pos;" + msg.obj.toString() + ":" + y + ":" + x);
                        break;
                }
            }
        }
    };



    public Handler handler = new Handler(){
        @Override
        public void handleMessage(Message msg){
            if( msg != null && msg.obj != null){
                if( msg.obj.toString().equals("act;DroneActivity") ) {
                    Intent intent = new Intent(TacticalActivity.this, DroneActivity.class);
                    startActivity(intent);
                    ////TacticalActivity.this.finish();
                }else if (msg.obj.toString().equals("act;MainActivity")) {
                    Intent intent = new Intent(TacticalActivity.this, MainActivity.class);
                    startActivity(intent);
                    TacticalActivity.this.finish();
                }else if(msg.obj.toString().substring(0,4).equals("per;")) {
                    String posMessage = msg.obj.toString().substring(4);
                    mapView.setPos(posMessage);
                    String[] persons = msg.obj.toString().substring(4).split(";");
                    for(int i=0;i<persons.length;i++) {
                        String[] info = persons[i].split(":");
                        String key = info[0];
                        try{
                            HpInfoView hpInfoView = infoViews.get(key);
                            float hp = Float.valueOf(info[3]);
                            hpInfoView.setHp((int)hp);
                            if( info.length > 5 )
                                hpInfoView.setOrder(info[4]);
                            else
                                hpInfoView.setOrder("F");
                        }catch (Exception e){}
                    }
                }else if(msg.obj.toString().substring(0,4).equals("set;")) {
                    if(infoViews != null){
                        infoViews.clear();
                        infoViews = null;
                    }
                    infoViews = new HashMap<>();
                    mapView.initPersonInfo(msg.obj.toString().substring(4));
                    String[] persons = msg.obj.toString().substring(4).split(";");
                    for(int i=0;i<persons.length;i++) {
                        String[] info = persons[i].split(":");
                        String key = info[0];
                        int idx = key.indexOf("Player");
                        if(idx < 0 || idx > 7){
                            HpInfoView hpInfoView = new HpInfoView(mContext,v_handler,persons[i],i);
                            infoViews.put(key, hpInfoView);
                            LinearLayout.LayoutParams layoutParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT,90);
                            layoutParams.setMargins(5, 5, 5, 5);
                            hpInfoView.setLayoutParams(layoutParams);
                            ll_info.addView(hpInfoView);
                        }
                    }
                }else if(msg.obj.toString().substring(0,4).equals("ene;")) {
                    String posMessage = msg.obj.toString().substring(4);
                    mapView.setEnemyPos(posMessage);
                }
            }
        }
    };
}
