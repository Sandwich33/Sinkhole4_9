package com.inu.sandwich.sinkhole.activity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.widget.FrameLayout;

import com.inu.sandwich.sinkhole.R;
import com.inu.sandwich.sinkhole.view.DroneCameraView;
import com.inu.sandwich.sinkhole.view.DroneJoyView;

import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.charset.Charset;
import java.util.Arrays;

/**
 * Created by 0xFF00FF00 on 2016-04-02.
 */
public class DroneActivity extends FullscreenActivity{

    DroneCameraView CameraView;
    DroneJoyView MoveFR;
    DroneJoyView MoveTurnUp;
    Thread thread;
    private boolean stopSend = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_drone);
        super.mContentView = findViewById(R.id.fullscreen_content);

        FrameLayout fl_rightJoy = (FrameLayout)findViewById(R.id.fl_rightJoy);
        FrameLayout fl_leftJoy = (FrameLayout)findViewById(R.id.fl_leftJoy);
        FrameLayout cam = (FrameLayout)findViewById(R.id.cam);

        CameraView = new DroneCameraView(this);
        MoveFR = new DroneJoyView(this);
        MoveTurnUp = new DroneJoyView(this);
        fl_rightJoy.addView(MoveTurnUp);
        fl_leftJoy.addView(MoveFR);
        cam.addView(CameraView);

        thread = new Thread(new Runnable() {
            @Override
            public void run() {
                String msg = "";
                while(!stopSend){
                    msg = "key;";
                    msg += -MoveFR.getMoveY()+":"; // Move Forward
                    msg += MoveFR.getMoveX()+":"; // Move Right
                    msg += -MoveTurnUp.getMoveY()+":"; // LookUp
                    msg += MoveTurnUp.getMoveX()+":"; // Turn
                    msg += "0.0"; // Move Up
                    tcp.sendMessage(msg);
                    try {
                        Thread.sleep(30);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        });
        tcp.setHandler(handler);
        tcp.sendMessage("ini;Drone");
    }

    protected void onDestroyed(){
        super.onDestroy();
        thread.interrupt();
        thread = null;
    }

    public void onStopDrone(View view){
        stopSend = true;
        tcp.stopDrone();
        return ;
    }

    private byte[] toBytes(char[] chars) {
        CharBuffer charBuffer = CharBuffer.wrap(chars);
        ByteBuffer byteBuffer = Charset.forName("UTF-8").encode(charBuffer);
        byte[] bytes = Arrays
                .copyOfRange(byteBuffer.array(),
                        byteBuffer.position(), byteBuffer.limit());
        Arrays.fill(charBuffer.array(), '\u0000'); // clear sensitive data
        Arrays.fill(byteBuffer.array(), (byte) 0); // clear sensitive data
        return bytes;
    }


    public Handler handler = new Handler(){
        @Override
        public void handleMessage(Message msg){

            if( msg.what < 0 ){
                //CameraView.sendData((char[])msg.obj);
                CameraView.drawImage(msg.arg1);
                return ;
            }
            if( msg != null && msg.obj != null){

                if (msg.obj.toString().equals("act;MainActivity")) {
                    Intent intent = new Intent(DroneActivity.this, MainActivity.class);
                    startActivity(intent);
                    DroneActivity.this.finish();
                }else if (msg.obj.toString().equals("ini;Drone")) {
                    tcp.sendMessage("ini;Drone");
                }else if (msg.obj.toString().equals("startDroneImage")) {
                    thread.start();
                }if (msg.obj.toString().equals("act;TacticalActivity")) {
                    Intent intent = new Intent(DroneActivity.this, TacticalActivity.class);
                    startActivity(intent);
                    //DroneActivity.this.finish();
                    DroneActivity.this.finish();
                }
            }
        }
    };
}
