package com.inu.sandwich.sinkhole.view;

import android.graphics.Canvas;
import android.view.SurfaceHolder;

/**
 * Created by 0xFF00FF00 on 2016-04-02.
 */
public class MinimapViewThread extends Thread {
    private SurfaceHolder surfaceHolder;
    private MinimapView view;
    private boolean isRun = false;
    public MinimapViewThread(SurfaceHolder _SurfaceHolder, MinimapView _view){
        surfaceHolder = _SurfaceHolder;
        view = _view;
    }

    public void setRunning(boolean _run){
        isRun = _run;
    }

    public void run(){
        Canvas canvas;
        while(isRun){
            canvas = null;
            try{
                canvas = surfaceHolder.lockCanvas(null);
                synchronized(surfaceHolder){
                    view.onDraw(canvas);
                }
            }finally {
                if(canvas != null){
                    surfaceHolder.unlockCanvasAndPost(canvas);
                }
            }
        }
    }
}
