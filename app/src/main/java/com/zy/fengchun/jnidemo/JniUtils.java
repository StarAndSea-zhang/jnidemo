package com.zy.fengchun.jnidemo;

/**
 * @author: on 2016/8/3 10:38
 * @emial : @517na.com
 * @description
 */
public class JniUtils {
    static {
        System.loadLibrary("NdkJniDemo");//之前在build.gradle里面设置的so名字，必须一致
    }

    public String mName = "Writer is";

    public static String mStaticName = "She's static name is ";

    public static native String getStringFromC();

    public native int count(int a,int b);

    public native String generateNewString(String str);

    public native String generateStringFromVariable();

    public native String accessStaticField();
}
