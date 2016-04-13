package com.inu.sandwich.sinkhole.activity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import com.inu.sandwich.sinkhole.R;
import com.inu.sandwich.sinkhole.TCP.TCP;

/**
 * Created by 0xFF00FF00 on 2016-04-01.
 */
public class MainActivity extends FullscreenActivity{

    private ImageView ivCable;
    private ImageView ivWifi;
    private TextView tvLoading;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_fullscreen);
        super.mContentView = findViewById(R.id.fullscreen_content);

        tvLoading = (TextView)findViewById(R.id.tv_loading);
        ivCable = (ImageView)findViewById(R.id.iv_cable);
        ivWifi = (ImageView)findViewById(R.id.iv_wifi);

        onCable(ivCable);

        if(tcp == null ) {
            tcp = new TCP();
            tcp.startTCPServer();
            tcp.setHandler(handler);
        }else{
            tcp.setHandler(handler);
        }
    }


    protected void onDestroyed(){
        super.onDestroy();
    }

    public Handler handler = new Handler(){
        @Override
        public void handleMessage(Message msg){
            if( msg != null && msg.obj != null) {
                if (msg.obj.toString().equals("act;WaitActivity")) {
                    Intent intent = new Intent(MainActivity.this, WaitActivity.class);
                    startActivity(intent);
                    MainActivity.this.finish();
                }else if (msg.obj.toString().equals("get;TabletName")) {
                    tcp.sendMessage("data;TabletName:"+android.os.Build.MODEL);
                }else if (msg.obj.toString().equals("act;TacticalActivity")) {
                    Intent intent = new Intent(MainActivity.this, TacticalActivity.class);
                    startActivity(intent);
                    MainActivity.this.finish();
                }
            }
        }
    };

    public void onCable(View view){
        ivCable.setImageResource(R.drawable.computer_s);
        ivWifi.setImageResource(R.drawable.internet);

        tvLoading.setText(android.os.Build.MODEL +"\n케이블 연결을 기다리는 중 입니다.");
    }

    public void onWifi(View view){
        ivCable.setImageResource(R.drawable.computer);
        ivWifi.setImageResource(R.drawable.internet_s);
        tvLoading.setText(android.os.Build.MODEL + "\n[" + TCP.getLocalIpAddress() + "] 연결을 기다리는 중 입니다.");
    }

}
