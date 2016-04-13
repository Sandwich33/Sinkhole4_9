package com.inu.sandwich.sinkhole.activity;

import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.drawable.AnimationDrawable;
import android.graphics.drawable.BitmapDrawable;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.BaseAdapter;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;

import com.google.android.gms.appindexing.Action;
import com.google.android.gms.appindexing.AppIndex;
import com.google.android.gms.common.api.GoogleApiClient;
import com.inu.sandwich.sinkhole.R;

import java.util.ArrayList;

/**
 * Created by 0xFF00FF00 on 2016-04-02.
 */
public class TeamActivity extends FullscreenActivity {


    private int gifres;
    private FrameLayout fl_img;
    private ImageView imgView;
    private AnimationDrawable frameAnimation;
    private TextView info;
    private ListView lv;
    private Adt adt;
    /**
     * ATTENTION: This was auto-generated to implement the App Indexing API.
     * See https://g.co/AppIndexing/AndroidStudio for more information.
     */
    private GoogleApiClient client;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_team);
        tcp.setHandler(handler);
        super.mContentView = findViewById(R.id.fullscreen_content);

        gifres = R.anim.gif_m4;

        fl_img = (FrameLayout) findViewById(R.id.fl_image);
        info = (TextView) findViewById(R.id.tv_info);
        lv = (ListView) findViewById(R.id.lv_team);
        adt = new Adt(this);
        lv.setAdapter(adt);

        String str = "- E.Dragon\n   M4A1\n   Lv.1";
        info.setText(str);

        lv.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                ListView listView = (ListView) parent;
                String str = "- " + adt.getItem(position) + "\n   " + adt.m_Listsub.get(position);
                switch (position) {
                    case 0:
                    case 1:
                        gifres = R.anim.gif_m4;
                        chAnim();
                        str = str+ "\n   Lv.1";
                        break;
                    case 2:
                        gifres = R.anim.gif_shotgun;
                        chAnim();
                        str = str+ "\n   Lv.1";
                        break;
                    case 3:
                        gifres = R.anim.gif_awp;
                        chAnim();
                        str = str+ "\n   Lv.1";
                        break;
                    default:
                        chImg();
                        str = str+ "\n   Lock";
                        break;
                }

                info.setText(str);
            }
        });
    }

    public void chImg(){
        if (imgView != null){
            imgView.setImageDrawable(null);
            imgView = null;
        }
        imgView = new ImageView(this);
        imgView.setVisibility(ImageView.VISIBLE);
        if (frameAnimation != null) {
            frameAnimation.stop();
        }
        fl_img.removeAllViews();
        imgView.setImageResource(android.R.drawable.ic_lock_idle_lock);
        fl_img.addView(imgView);
    }

    public void chAnim() {
        if (imgView != null){
            imgView.setImageDrawable(null);
            imgView = null;
        }
        imgView = new ImageView(this);
        imgView.setVisibility(ImageView.VISIBLE);
        if (frameAnimation != null) {
            frameAnimation.stop();
        }
        fl_img.removeAllViews();
        imgView.setImageResource(gifres);
        fl_img.addView(imgView);
        frameAnimation = (AnimationDrawable) imgView.getDrawable();
        frameAnimation.start();
    }

    public void onWindowFocusChanged(boolean hasFocus) {
        chAnim();
        super.onWindowFocusChanged(hasFocus);
    }

    public Handler handler = new Handler(){
        @Override
        public void handleMessage(Message msg){
            if( msg != null && msg.obj != null){
                if( msg.obj.toString().equals("get;checkTeam") ) {
                    tcp.sendMessage("data;state:ok");
                }else if (msg.obj.toString().equals("act;TacticalActivity")) {
                    Intent intent = new Intent(TeamActivity.this, TacticalActivity.class);
                    startActivity(intent);
                    TeamActivity.this.finish();
                }else if (msg.obj.toString().equals("act;MainActivity")) {
                    Intent intent = new Intent(TeamActivity.this, MainActivity.class);
                    startActivity(intent);
                    TeamActivity.this.finish();
                }
            }
        }
    };

    private class Adt extends BaseAdapter {

        private Context context;

        private ArrayList<String> m_List;
        public ArrayList<String> m_Listsub;

        public Adt(Context _context) {
            context = _context;
            m_List = new ArrayList<String>();
            m_Listsub = new ArrayList<String>();
            m_List.add("E.Dragon");
            m_Listsub.add("M4A1");
            m_List.add("Seonggyun Kim");
            m_Listsub.add("M4A1");
            m_List.add("K.silver");
            m_Listsub.add("Shotgun");
            m_List.add("Seongyun Min");
            m_Listsub.add("AWP");
            m_List.add("SK.Kelly");
            m_Listsub.add("K2");
            m_List.add("Liam Evans");
            m_Listsub.add("AK-47");
        }

        @Override
        public int getCount() {
            if (m_List != null)
                return m_List.size();
            return 0;
        }

        @Override
        public Object getItem(int position) {
            if (m_List != null)
                return m_List.get(position);
            return null;
        }

        @Override
        public long getItemId(int position) {
            return position;
        }

        @Override
        public View getView(int position, View convertView, ViewGroup parent) {
            //final int pos = position;
            //final Context context = parent.getContext();
            // 리스트가 길어지면서 현재 화면에 보이지 않는 아이템은 converView가 null인 상태로 들어 옴
            if (convertView == null) {
                // view가 null일 경우 커스텀 레이아웃을 얻어 옴
                LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
                convertView = inflater.inflate(R.layout.listitem_team, null);
            }
            TextView tvTitle = (TextView) convertView.findViewById(R.id.tv_title);
            TextView tvSub = (TextView) convertView.findViewById(R.id.tv_sub);
            ImageView imageView = (ImageView) convertView.findViewById(R.id.iv_icon);
            tvTitle.setText(m_List.get(position));
            tvSub.setText(m_Listsub.get(position));
            switch (position){
                case 0:
                    imageView.setImageResource(R.drawable.edragon);
                    break;
                case 1:
                    imageView.setImageResource(R.drawable.sgk);
                    break;
                case 2:
                    imageView.setImageResource(R.drawable.ksilver);
                    break;
                case 3:
                    imageView.setImageResource(R.drawable.sym);
                    break;

            }

            return convertView;
        }
    }
}
