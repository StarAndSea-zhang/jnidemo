/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_zy_fengchun_jnidemo_JniUtils */
#include <android/log.h>
#include <string.h>
#define LOG_TAG "TAG"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,LOG_TAG,__VA_ARGS__)
#ifndef _Included_com_zy_fengchun_jnidemo_JniUtils
#define _Included_com_zy_fengchun_jnidemo_JniUtils
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_zy_fengchun_jnidemo_JniUtils
 * Method:    getStringFromC
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_zy_fengchun_jnidemo_JniUtils_getStringFromC
        (JNIEnv *, jclass);

/*
 * Class:     com_zy_fengchun_jnidemo_JniUtils
 * Method:    count
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_zy_fengchun_jnidemo_JniUtils_count
        (JNIEnv *, jobject, jint, jint);

/*
 * 根据入参产生一个新的string
 * Class:     com_zy_fengchun_jnidemo_JniUtils
 * Method:    generateNewString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_zy_fengchun_jnidemo_JniUtils_generateNewString
        (JNIEnv *, jobject,jstring);

/*
 * 访问成员变量
 * Class:     com_zy_fengchun_jnidemo_JniUtils
 * Method:    generateStringFromVariable
 */
JNIEXPORT jstring JNICALL Java_com_zy_fengchun_jnidemo_JniUtils_generateStringFromVariable
        (JNIEnv *, jobject);

/*
 * 访问成员变量
 * Class:     com_zy_fengchun_jnidemo_JniUtils
 * Method:    accessStaticField
 */
JNIEXPORT jstring JNICALL Java_com_zy_fengchun_jnidemo_JniUtils_accessStaticField
        (JNIEnv *, jobject);
#ifdef __cplusplus
}
#endif
#endif