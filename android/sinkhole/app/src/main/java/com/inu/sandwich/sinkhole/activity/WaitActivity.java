package com.inu.sandwich.sinkhole.activity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;

import com.inu.sandwich.sinkhole.R;

/**
 * Created by 0xFF00FF00 on 2016-04-02.
 */
public class WaitActivity extends FullscreenActivity{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_wait);
        super.mContentView = findViewById(R.id.fullscreen_content);


        tcp.setHandler(handler);
    }



    public Handler handler = new Handler(){
        @Override
        public void handleMessage(Message msg){
            if( msg != null && msg.obj != null){
                if( msg.obj.toString().equals("act;TeamActivity") ) {
                    Intent intent = new Intent(WaitActivity.this, TeamActivity.class);
                    startActivity(intent);
                    WaitActivity.this.finish();
                }else if (msg.obj.toString().equals("act;MainActivity")) {
                    Intent intent = new Intent(WaitActivity.this, MainActivity.class);
                    startActivity(intent);
                    WaitActivity.this.finish();
                }else if (msg.obj.toString().equals("act;TacticalActivity")) {
                    Intent intent = new Intent(WaitActivity.this, TacticalActivity.class);
                    startActivity(intent);
                    WaitActivity.this.finish();
                }
            }
        }
    };
}
