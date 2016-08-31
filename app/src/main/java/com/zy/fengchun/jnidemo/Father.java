package com.zy.fengchun.jnidemo;

import android.util.Log;

import java.util.Date;

/**
 * @author: on 2016/8/3 10:38
 * @emial : @517na.com
 * @description
 */
public class Father {
    public String getFatherName(){
        String str = "fathername"+new Date().getTime();
        Log.e("TAG",str);
        return str;
    }

    public void sayHi(){
        System.out.println("父亲打招呼....");
    }
}
