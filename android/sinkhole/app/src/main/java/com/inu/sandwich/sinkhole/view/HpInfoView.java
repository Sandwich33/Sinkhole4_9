package com.inu.sandwich.sinkhole.view;

import android.content.Context;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.drawable.BitmapDrawable;
import android.media.Image;
import android.os.Handler;
import android.util.AttributeSet;
import android.util.Log;
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

/**
 * Created by 0xFF00FF00 on 2016-04-02.
 */
public class HpInfoView extends FrameLayout {
    private Handler handler;
    private int color;
    private ImageView imageView;
    private TextView textView;
    private ProgressBar progressBar;
    private String key;

    public HpInfoView(Context context) {
        super(context);
        initView(context);
    }

    public HpInfoView(Context context,Handler _handler,String initMessage,int index) {
        super(context);
        initView(context);

        handler = _handler;

        int[] Color = {0xFF3E5EE8,0xFFE5DE47,0xFFC832DC,0xFF26C823};
        color = Color[index%4];
        String[] info = initMessage.split(":");
        key = info[0];
        imageView.setBackgroundColor(color);
        textView.setText(info[0].substring(0, info[0].indexOf("_")));
        float hp = Float.valueOf(info[3]);
        progressBar.setProgress((int) hp);
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

    public void setOrder(String _order){
        if(_order.equals("T")){
            imageView.setImageResource(R.drawable.icon_run);
        }else{
            imageView.setImageResource(R.drawable.two);
        }
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
            return true;
        }
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
                handler.sendMessage(handler.obtainMessage(1,key));
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
    }
}
