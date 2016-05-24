package com.inu.sandwich.sinkhole.view;

import android.content.ClipData;
import android.content.Context;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.Point;
import android.graphics.PorterDuff;
import android.graphics.drawable.BitmapDrawable;
import android.os.Build;
import android.os.Handler;
import android.util.Log;
import android.view.DragEvent;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;

import com.inu.sandwich.sinkhole.R;
import com.inu.sandwich.sinkhole.Utils.PersonData;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

/**
 * Created by 0xFF00FF00 on 2016-04-02.
 */
public class MinimapView extends SurfaceView implements SurfaceHolder.Callback, View.OnDragListener {
    private class PersonInfo{
        Point pos;
        int color;
        boolean showF;
        Point flage;
        boolean alive;
    }
    private MinimapViewThread ViewThread;
    private float initX = 0;
    private float initY = 0;
    private int startX = 1156;
    private int startY = 2656;
    private boolean onTouch = false;
    private int sizeW;
    private int sizeH;
    private Bitmap mapbitmap;
    private int mapW,mapH;
    private HashMap<String,PersonInfo> persons;
    private Handler handler;
    private String CameraKey;
    private ArrayList<Point> enemys;

    public MinimapView(Context context,Handler _handler) {
        super(context);
        getHolder().addCallback(this);
        handler = _handler;
        ViewThread = new MinimapViewThread(getHolder(),this);
        Resources res = getResources();
        BitmapDrawable bd = (BitmapDrawable)res.getDrawable(R.drawable.minimap);
        mapbitmap = bd.getBitmap();
        mapW = mapbitmap.getWidth();
        mapH = mapbitmap.getHeight();
        CameraKey = null;
        enemys = new ArrayList<>();
        this.setOnDragListener(this);
    }

    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        sizeW = w;
        sizeH = h;
        super.onSizeChanged(w, h, oldw, oldh);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        // return super.onTouchEvent(event);
        int action = event.getAction();
        if (action == MotionEvent.ACTION_MOVE) {
            float x = event.getX();
            float y = event.getY();
            startX += (initX-x)/5;
            startY += (initY-y)/5;

            startX = Math.max(startX,1);
            startY = Math.max(startY,1);

            startX = Math.min(startX, mapW - sizeW - 1);
            startY = Math.min(startY, mapH - sizeH-177);
            CameraKey = null;
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

    public void initPersonInfo(ArrayList<PersonData> data){
        if( persons != null ){
            persons.clear();
            persons = null;
        }
        persons = new HashMap<>();

        for(int i=0;i<data.size();i++) {
            PersonData personData = data.get(i);
            String key = personData.Name;
            int x = personData.pos.x;
            int y = personData.pos.y;
            int[] Color = {0xFF3E5EE8,0xFFE5DE47,0xFFC832DC,0xFF26C823,0xFF111111};
            PersonInfo personInfo = new PersonInfo();
            personInfo.pos = new Point(x+(440+sizeW),y+1899);
            personInfo.flage = new Point(0,0);
            personInfo.color = Color[i%5];
            personInfo.showF = false;
            personInfo.alive = true;
            persons.put(key, personInfo);

            if(i == data.size()-1){
                CameraKey = key;
            }
        }
    }

    public void setEnemyPos(ArrayList<Point> msg){
        enemys.removeAll(enemys);
        for(int i=0;i<msg.size();i++) {
            int x = msg.get(i).x;
            int y = msg.get(i).y;
            enemys.add(new Point(x+(440+sizeW),y+1899));
        }
    }

    public void setPos(ArrayList<PersonData> data){
        if( persons == null || persons.size() < 1 ){
            initPersonInfo(data);
            handler.sendMessage(handler.obtainMessage(4, data));
            return;
        }

        Iterator<String> iter = persons.keySet().iterator();
        while (iter.hasNext()) {
            String key = iter.next();
            persons.get(key).alive = false;
        }

        for(int i=0;i<data.size();i++) {
            PersonData personData = data.get(i);
            String key = personData.Name;
            int x = personData.pos.x;
            int y = personData.pos.y;
            PersonInfo personInfo = persons.get(key);
            personInfo.alive = true;
            personInfo.pos.x = x+(440+sizeW);
            personInfo.pos.y = y+1899;
            if(personData.order){
                personInfo.showF = true;
                personInfo.flage.x = personData.order_pos.x+(440+sizeW);
                personInfo.flage.y = personData.order_pos.y+1899;

                //Log.d("TAG","("+personInfo.pos.toString()+") ; ("+personInfo.flage.toString()+") ("+personData.pos.toString()+") ; ("+personData.order_pos.toString()+")");
            }else{
                personInfo.showF = false;
            }
        }
    }

    public void setCameraKeyPlayer(){
        Iterator<String> iter = persons.keySet().iterator();
        while (iter.hasNext()) {
            String key = iter.next();
            int idx = key.indexOf("Player");
            if( idx >= 0 && idx < 7 ){
                CameraKey = key;
                return ;
            }
        }
    }

    public void setCameraKey(String key){
        try{
            if( persons.containsKey(key) ){
                CameraKey = key;
            }
        }catch (Exception e){}
    }

    public void onDraw(Canvas canvas){
        if( CameraKey != null && CameraKey.length() > 0){
            PersonInfo value = persons.get(CameraKey);
            startX = -(sizeW/2)+value.pos.x;
            startY = -(sizeH/2)+value.pos.y;
            startX = Math.max(startX,1);
            startY = Math.max(startY,1);

            startX = Math.min(startX, mapW - sizeW-1);
            startY = Math.min(startY, mapH - sizeH-177);
        }

        // Draw BG
        Paint paint = new Paint();
        try {
            //Bitmap vbit = Bitmap.createBitmap(mapbitmap, startX, startY, sizeW, sizeH);
            //canvas.drawBitmap(vbit, 0, 0, paint);
            //vbit.recycle();
            canvas.drawBitmap(mapbitmap, -startX, -startY, paint);
        }catch (Exception e){};

        // Draw Cahr
        try {
            paint.setStyle(Paint.Style.FILL);
            Iterator<String> iter = persons.keySet().iterator();
            while (iter.hasNext()) {
                String key = iter.next();
                PersonInfo value = persons.get(key);
                if( !value.alive)
                    continue;
                paint.setColor(value.color);
                if ((startX < value.pos.x && value.pos.x < (startX + sizeW)) && (startY < value.pos.y && value.pos.y < (startY + sizeH))) {
                    canvas.drawCircle(value.pos.x - startX, value.pos.y - startY, 20, paint);
                }
                if (value.showF && (startX < value.flage.x && value.flage.x < (startX + sizeW)) && (startY < value.flage.y && value.flage.y < (startY + sizeH))) {
                    Path path = new Path();
                    Paint stroke = new Paint();
                    stroke.setStyle(Paint.Style.STROKE);
                    stroke.setStrokeWidth(3);
                    stroke.setColor(Color.BLACK);
                    int x = value.flage.x - startX;
                    int y = value.flage.y - startY;
                    path.moveTo(x, y);
                    path.lineTo(x - 10, y - 30);
                    path.lineTo(x+10, y-30);
                    path.lineTo(x, y);
                    canvas.drawPath(path, paint);
                    canvas.drawPath(path, stroke);
                    path.close();
                }
            }
        }catch (Exception e){};

        // DrawEnemy
        paint.setColor(Color.RED);
        for(int i=0;i<enemys.size();i++){
            Point pos = enemys.get(i);
            if ((startX < pos.x && pos.x < (startX + sizeW)) && (startY < pos.y && pos.y < (startY + sizeH))) {
                try {
                    canvas.drawCircle(pos.x - startX, pos.y - startY, 20, paint);
                }catch (Exception e){}
            }
        }
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        ViewThread.setRunning(true);
        ViewThread.start();
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {

    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        boolean retry= true;
        ViewThread.setRunning(false);
        while(retry){
            try{
                ViewThread.join();
                retry=false;
            }catch (InterruptedException e){}
        }
    }

    @Override
    public boolean onDrag(View v, DragEvent event) {
        // 이벤트 시작
        switch (event.getAction()) {
            case DragEvent.ACTION_DROP:
                //ClipData clipData = event.getClipData();
                float x = event.getX();
                float y = event.getY();
                x = (((x +startX)-(440+sizeW))*(-12.5f));
                y = (((y+startY)-1899)*12.5f);
                handler.sendMessage(handler.obtainMessage(3, (int) (x * 1000), (int) (y * 1000), event.getClipDescription().getLabel().toString()));
                break;
            case DragEvent.ACTION_DRAG_STARTED:
                break;
            default:
                break;
        }
        return true;
    }
}
