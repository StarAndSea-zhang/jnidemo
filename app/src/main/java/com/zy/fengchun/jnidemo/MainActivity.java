package com.zy.fengchun.jnidemo;

import java.util.ArrayDeque;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadFactory;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

import android.app.Activity;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
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
        mTVStaticName.setText(JniUtils.mStaticName);
    }
}
