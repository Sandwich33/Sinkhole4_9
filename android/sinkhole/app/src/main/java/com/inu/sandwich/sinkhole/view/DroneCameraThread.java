package com.inu.sandwich.sinkhole.view;

import android.graphics.Canvas;
import android.view.SurfaceHolder;

/**
 * Created by 0xFF00FF00 on 2016-04-02.
 */
public class DroneCameraThread extends Thread {
    private SurfaceHolder surfaceHolder;
    private DroneCameraView droneJoyView;
    private boolean isRun = false;
    public DroneCameraThread(SurfaceHolder _SurfaceHolder, DroneCameraView _DroneJoyView){
        surfaceHolder = _SurfaceHolder;
        droneJoyView = _DroneJoyView;
    }

    public void setRunning(boolean _run){
        isRun = _run;
    }

    public void run(){
        Canvas canvas;
        while(isRun)
        {
            canvas = null;
            try{
                canvas = surfaceHolder.lockCanvas(null);
                synchronized(surfaceHolder){
                    droneJoyView.onDraw(canvas);
                }
            }finally {
                if(canvas != null){
                    surfaceHolder.unlockCanvasAndPost(canvas);
                }
            }
        }
    }
}
