package com.zy.fengchun.jnidemo;

import android.util.Log;

/**
 * @author: on 2016/8/3 10:38
 * @emial : @517na.com
 * @description
 */
public class UtilsLog {

    public static final String TAG = UtilsLog.class.getSimpleName();

    public static final boolean DEBUG = BuildConfig.API_ENV;

    private static final int v = 0x00001;
    private static final int i = 0x00010;
    private static final int w = 0x00100;
    private static final int d = 0x01000;
    private static final int e = 0x10000;

    public static void v(String log) {
        print(log, v);
    }

    public static void d(String log) {
        print(log, d);
    }

    public static void i(String log) {
        print(log, i);
    }

    public static void w(String log) {
        print(log, w);
    }

    public static void e(String log) {
        print(log, e);
    }

    private static void print(String log, int level) {
        if (!DEBUG)
            return;

        StackTraceElement[] stackTraceElements = Thread.currentThread().getStackTrace();
        int currentIndex = -1;
        String methodName = "";
        for (StackTraceElement element :stackTraceElements) {
            methodName = element.getMethodName();
            if (methodName.compareTo("v") == 0 || methodName.compareTo("d") == 0
                    || methodName.compareTo("i") == 0
                    || methodName.compareTo("w") == 0
                    || methodName.compareTo("e") == 0
                    || methodName.compareTo("a") == 0) {
                currentIndex = i + 1;
                break;
            }
        }

        String fullClassName = stackTraceElements[currentIndex].getClassName();
        String className = fullClassName.substring(fullClassName.lastIndexOf(".") + 1);
        String lineNumber = String.valueOf(stackTraceElements[currentIndex].getLineNumber());

        String formatLog = "at " + fullClassName
                + "."
                + methodName
                + "("
                + className
                + ".java:"
                + lineNumber
                + ") \n"
                + log;

        switch (level) {
            case v:
                Log.v(TAG, formatLog);
                break;
            case i:
                Log.i(TAG, formatLog);
                break;
            case d:
                Log.d(TAG, formatLog);
                break;
            case w:
                Log.w(TAG, formatLog);
                break;
            case e:
                Log.e(TAG, formatLog);
                break;
            default:
                break;
        }
    }
}
