package com.inu.sandwich.sinkhole.view;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.PorterDuff;
import android.util.Log;
import android.util.Size;
import android.util.SizeF;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

/**
 * Created by 0xFF00FF00 on 2016-04-02.
 */
public class DroneJoyView extends SurfaceView implements SurfaceHolder.Callback {
    private DroneJoyViewThread droneJoyViewThread;
    private float initX = 0;
    private float initY = 0;
    private boolean onTouch = false;
    private float sizeW;
    private float sizeH;
    private float move_x = 0;
    private float move_y = 0;

    public DroneJoyView(Context context) {
        super(context);
        getHolder().addCallback(this);
        droneJoyViewThread = new DroneJoyViewThread(getHolder(),this);
    }

    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        sizeW = w;
        sizeH = h;
        super.onSizeChanged(w, h, oldw, oldh);
    }

    public float getMoveX(){
        return move_x;
    }

    public float getMoveY(){
        return move_y;
    }


    @Override
    public boolean onTouchEvent(MotionEvent event) {
        // return super.onTouchEvent(event);
        int action = event.getAction();
        if (action == MotionEvent.ACTION_MOVE) {
            initX = event.getX();
            initY = event.getY();
            onTouch = true;
        } else if (action == MotionEvent.ACTION_DOWN) {
            initX = event.getX();
            initY = event.getY();
            onTouch = true;
        } else if (action == MotionEvent.ACTION_UP) {
            initX = 0;
            initY = 0;
            onTouch = false;
            performClick();
        }

        return true;
    }


    public void onDraw(Canvas canvas){
        float w = sizeW / 2;
        float h = sizeH / 2;

        canvas.drawColor(Color.TRANSPARENT, PorterDuff.Mode.CLEAR);

        Paint mPaint = new Paint();
        mPaint.setStyle(Paint.Style.STROKE);
        mPaint.setColor(0xffc1c1c1);
        mPaint.setStrokeWidth(7);
        canvas.drawCircle(w, h, w - 5, mPaint);
        mPaint.setColor(0xffa7a7a7);
        mPaint.setStrokeWidth(3);
        canvas.drawCircle(w, h, w - 5, mPaint);

        float x = w;
        float y = h;
        if(onTouch) {
            float inX = initX - w;
            float inY = initY - h;
            float C = (float) (Math.sqrt((inX * inX) + (inY * inY)));
            if((w/2) <= C){
                x = (inX * (w / 2)) / C + w;
            }else{
                x = initX;
            }
            if((h/2) <= C){
                y = (inY * (w / 2)) / C + h;
            }else{
                y = initY;
            }

            move_x = (x - w)/(w/2);
            move_y = (y - h)/(h/2);
        }else{
            move_x = 0;
            move_y = 0;
        }

        mPaint.setStyle(Paint.Style.FILL);
        mPaint.setColor(0xffc1c1c1);
        canvas.drawCircle(x, y, (sizeW / 4.0f), mPaint);
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        droneJoyViewThread.setRunning(true);
        droneJoyViewThread.start();
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {

    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        boolean retry= true;
        droneJoyViewThread.setRunning(false);
        while(retry){
            try{
                droneJoyViewThread.join();
                retry=false;
            }catch (InterruptedException e){}
        }
    }
}
