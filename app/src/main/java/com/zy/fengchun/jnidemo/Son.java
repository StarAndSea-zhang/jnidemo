package com.zy.fengchun.jnidemo;

import android.util.Log;

import java.util.Date;

/**
 * @author: on 2016/8/3 10:38
 * @emial : @517na.com
 * @description
 */
public class Son extends Father {

    @Override
    public String getFatherName(){
        String str = "sonname"+new Date().getTime();
        Log.e("TAG",str);
        return str;
    }

    @Override
    public void sayHi(){
        System.out.println("儿子打招呼....");
    }
}
