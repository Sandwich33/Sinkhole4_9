package com.inu.sandwich.sinkhole.view;

import android.content.ClipData;
import android.content.ClipDescription;
import android.content.Context;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.drawable.BitmapDrawable;
import android.media.AudioManager;
import android.media.Image;
import android.media.SoundPool;
import android.opengl.Visibility;
import android.os.Handler;
import android.util.AttributeSet;
import android.util.Log;
import android.view.DragEvent;
import android.view.GestureDetector;
import android.view.GestureDetector.SimpleOnGestureListener;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.RelativeLayout;
import android.widget.TextView;

import com.inu.sandwich.sinkhole.R;
import com.inu.sandwich.sinkhole.Utils.PersonData;

/**
 * Created by 0xFF00FF00 on 2016-04-02.
 */
public class HpInfoView extends FrameLayout  implements View.OnDragListener {
    private Handler handler;
    private int color;
    private ImageView imageView;
    private TextView textView;
    private ProgressBar progressBar;
    private String key;
    private SoundPool soundPool;
    private int sound;
    private boolean alive = true;

    public HpInfoView(Context context) {
        super(context);
        initView(context);
    }

    public HpInfoView(Context context,Handler _handler,PersonData initData,int index) {
        super(context);
        initView(context);

        handler = _handler;

        int[] Color = {0xFF3E5EE8,0xFFE5DE47,0xFFC832DC,0xFF26C823};
        color = Color[index%4];
        key = initData.Name;
        imageView.setBackgroundColor(color);
        textView.setText(key.substring(0, key.indexOf("_")));
        progressBar.setProgress(initData.hp);
        this.setOnDragListener(this);

        soundPool = new SoundPool(1, AudioManager.STREAM_ALARM,0);
        Log.d("key","key ; ["+key+"]");
        if(key.equals("AWP_AI_Person")){
            sound = soundPool.load(context,R.raw.die_yun,1);
        }else if(key.equals("Shotgun_AI_Person")){
            sound = soundPool.load(context,R.raw.die_ho,1);
        }else if(key.equals("M4A1_AI_Person")){
            sound = soundPool.load(context,R.raw.die_ryong,1);
        }else if(key.equals("M4A1_AI_Person2")){
            sound = soundPool.load(context,R.raw.die_gyun,1);
        }
    }

    public HpInfoView(Context context, AttributeSet attrs) {
        super(context, attrs);
        initView(context);
    }

    public HpInfoView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        initView(context);
    }

    private void initView(Context context){
        LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View view = inflater.inflate(R.layout.listitem_hp, null);
        this.addView(view);

        imageView = (ImageView)view.findViewById(R.id.iv_icon);
        textView = (TextView)view.findViewById(R.id.tv_gun);
        progressBar = (ProgressBar)view.findViewById(R.id.progressBar);

        gestureDetector = new GestureDetector(context, new GestureListener());
    }

    public void setHp(int hp){
        progressBar.setProgress(hp);
    }

    public void setOrder(boolean _order){
        if(_order){
            imageView.setImageResource(R.drawable.icon_run);
        }else{
            imageView.setImageResource(R.drawable.two);
        }
    }
    public void setDeath(){
        if( !alive )
            return;
        alive = false;
        imageView.setImageResource(R.drawable.bullet_head);
        soundPool.play(sound, 1, 1, 0, 0, 1);
    }

    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        super.onSizeChanged(w, h, oldw, oldh);
    }

    GestureDetector gestureDetector;

    @Override
    public boolean onTouchEvent(MotionEvent e) {
        return gestureDetector.onTouchEvent(e);
    }


    private class GestureListener extends GestureDetector.SimpleOnGestureListener {

        @Override
        public boolean onDown(MotionEvent e) {

            //FrameLayout hpInfoView = new FrameLayout(getContext());

            HpInfoView hpInfoView = HpInfoView.this;

            if( hpInfoView.progressBar.getProgress() < 1)
                return false;

            //Log.d("DragClickListener","Start : "+msg.obj.toString());
            ClipData.Item item = new ClipData.Item(key);//(CharSequence) view.getTag());
            String[] mimeTypes = { ClipDescription.MIMETYPE_TEXT_PLAIN };
            ClipData data = new ClipData(key,mimeTypes, item);
            View.DragShadowBuilder shadowBuilder = new View.DragShadowBuilder(hpInfoView);

            hpInfoView.startDrag(data, // data to be dragged
                    shadowBuilder,//shadowBuilder, // drag shadow
                    hpInfoView, // 드래그 드랍할  Vew
                    0 // 필요없은 플래그
            );

            return true;
        }
        /*
        @Override
        public boolean onSingleTapUp(MotionEvent e) {
            if (handler != null){
                handler.sendMessage(handler.obtainMessage(0,key));
                Log.d("Double Tap", "onSingleTapUp");
                return true;
            }
            return false;
        }

        @Override
        public void onLongPress(MotionEvent e) {
            if (handler != null){
                //handler.sendMessage(handler.obtainMessage(1,key));
            }
        }

        // event when double tap occurs
        @Override
        public boolean onDoubleTap(MotionEvent e) {
            if (handler != null){
                handler.sendMessage(handler.obtainMessage(2,key));
                Log.d("Double Tap", "onDoubleTap");
                return true;
            }
            return false;
        }
        */
    }


    @Override
    public boolean onDrag(View v, DragEvent event) {
        // 이벤트 시작
        switch (event.getAction()) {
            case DragEvent.ACTION_DROP:
                if (handler != null){
                    handler.sendMessage(handler.obtainMessage(0,key));
                    return true;
                }
                break;
            default:
                break;
        }
        return true;
    }
}
