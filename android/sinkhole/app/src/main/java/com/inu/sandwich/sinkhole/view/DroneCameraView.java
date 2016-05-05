package com.inu.sandwich.sinkhole.view;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.PorterDuff;
import android.os.Environment;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import java.io.File;
import java.io.IOException;

/**
 * Created by 0xFF00FF00 on 2016-04-08.
 */
public class DroneCameraView extends SurfaceView implements SurfaceHolder.Callback {
    private DroneCameraThread droneCameraThread;
    char[] byteArray;
    boolean up = false;
    private float sizeW;
    private float sizeH;
    private boolean dimg = false;
    private Bitmap bmp;
    private int tc;

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

    public File getTempFile(String fileName){
        File file=null;
        try{
            file = File.createTempFile( fileName, ".bmp", getContext().getFilesDir());
        }catch( IOException e){

        }
        return file;
    }

    public void drawImage(int tCnt){
        Log.d("TCP","draw "+tCnt);
        tc = tCnt;
        dimg = true;
    }

    public void onDraw(Canvas canvas) {
        //if(dimg) {
            try {
                String fname = (new File(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES), "temp_"+tc+".bmp")).getAbsolutePath();
                Bitmap loadBmp = BitmapFactory.decodeFile(fname);//(getTempFile("temp"));
                if (loadBmp != null) {
                    //bmp = loadBmp;
                    canvas.drawBitmap(loadBmp, 0, 0, new Paint());
                } else {
                }
            } catch (Exception e) {
            }
            dimg = false;
        //}

       // if (bmp != null) {
       // }
    }

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
