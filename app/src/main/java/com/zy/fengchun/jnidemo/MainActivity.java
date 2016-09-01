package com.zy.fengchun.jnidemo;

import java.util.ArrayDeque;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadFactory;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.drawable.BitmapDrawable;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import org.w3c.dom.Text;

public class MainActivity extends Activity {

    private TextView mTextView;
    private TextView mTVName;
    private TextView mTVStaticName;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mTextView = (TextView) findViewById(R.id.tv_text);
        mTVName = (TextView) findViewById(R.id.tv_name);
        mTVStaticName = (TextView) findViewById(R.id.tv_staticname);

        JniUtils jniUtils = new JniUtils();
        mTextView.setText(jniUtils.generateNewString("writer is"));
        jniUtils.generateStringFromVariable();
        mTVName.setText(jniUtils.mName);
        jniUtils.accessStaticField();
        mTVStaticName.setText(jniUtils.chineseChars("this is"));
        jniUtils.accessConstructor();
        initDrawable();
//        jniUtils.accessNonvirtualMethod();
//        int[] arr = {9,1,7,8,2,3,6,12,4};
//        arr = jniUtils.getArray(10);
//        for (int i = 0;i< arr.length;i++)
//        {
//            Log.e("TAG",arr[i]+"");
//        }
//        initDrawable();
    }

    private void initDrawable() {
        Bitmap bitmap = ((BitmapDrawable) getResources().getDrawable(
                R.mipmap.ic_img)).getBitmap();
        int w = bitmap.getWidth(), h = bitmap.getHeight();
        int[] pix = new int[w * h];
        bitmap.getPixels(pix, 0, w, 0, 0, w, h);
        int [] resultPixes=OpenCVTest.gray(pix,w,h);
//        Bitmap result = Bitmap.createBitmap(w,h, Bitmap.Config.RGB_565);
//        result.setPixels(resultPixes, 0, w, 0, 0,w, h);
//        ImageView img=(ImageView)findViewById(R.id.imageview);
//        img.setImageBitmap((result));
    }
}
