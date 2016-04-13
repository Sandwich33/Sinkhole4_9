package com.inu.sandwich.sinkhole.view;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.PorterDuff;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

/**
 * Created by 0xFF00FF00 on 2016-04-08.
 */
public class DroneCameraView extends SurfaceView implements SurfaceHolder.Callback {
    private DroneCameraThread droneCameraThread;
    char[] byteArray;
    boolean up = false;
    private float sizeW;
    private float sizeH;

    public DroneCameraView(Context context) {
        super(context);
        getHolder().addCallback(this);
        droneCameraThread = new DroneCameraThread(getHolder(),this);
    }

    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        sizeW = w;
        sizeH = h;
        super.onSizeChanged(w, h, oldw, oldh);
    }

    public void onDraw(Canvas canvas) {
        if( byteArray != null && byteArray.length > 500 ) {
            try {
                //tcanvas.drawColor(Color.GREEN);
            }catch (Exception e){}

            int k=0;
            int y = byteArray[0];
            y =  y + (byteArray[1] << 8);
            k=2;
            while(k < byteArray.length){
                Paint mPaint = new Paint();
                mPaint.setStyle(Paint.Style.FILL_AND_STROKE);
                //mPaint.setStrokeWidth(4);
                mPaint.setARGB(255, byteArray[k], byteArray[k], byteArray[k]);
                k++;
                canvas.drawPoint(k-2,y,mPaint);
            }
            up = false;
        }else{
        }
    }

//    public void sendData(byte[] _byteArray){
////        synchronized (byteArray) {
//            byteArray = _byteArray;
//        Log.d("TCP","byteArray len : "+byteArray.length);
//            up = true;
// //       }
//    }

    public void sendData(char[] _byteArray){
//        synchronized (byteArray) {
        byteArray = _byteArray;
        //Log.d("TCP","byteArray len : "+byteArray.length);
        String hex = String.format("%02x %02x %02x %02x", (int) byteArray[0],(int) byteArray[1],(int) byteArray[2],(int) byteArray[3]);
        Log.d("drone",hex);
        hex = String.format("%02x %02x %02x %02x", (int) byteArray[4],(int) byteArray[5],(int) byteArray[6],(int) byteArray[7]);
        Log.d("drone",hex);
        up = true;
    }
    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        droneCameraThread.setRunning(true);
        droneCameraThread.start();
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {

    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        boolean retry= true;
        droneCameraThread.setRunning(false);
        while(retry){
            try{
                droneCameraThread.join();
                retry=false;
            }catch (InterruptedException e){}
        }
    }
}
