package com.zy.fengchun.jnidemo;

/**
 * @author: on 2016/8/3 10:38
 * @emial : @517na.com
 * @description
 */
public class OpenCVTest {
    static {
        System.loadLibrary("NdkJniDemo");
    }

    public static native int[] gray(int[] buf, int w, int h);
}
