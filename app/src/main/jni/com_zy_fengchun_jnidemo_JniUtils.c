#include "com_zy_fengchun_jnidemo_JniUtils.h"
JNIEXPORT jstring JNICALL Java_com_zy_fengchun_jnidemo_JniUtils_getStringFromC
        (JNIEnv * env, jclass jclass){
    jstring jstr = (*env)->NewStringUTF(env,"我们都测试了几次啦");
    return jstr;
}

JNIEXPORT jint JNICALL Java_com_zy_fengchun_jnidemo_JniUtils_count
        (JNIEnv * env, jobject jobj, jint a, jint b){
    //将jint整形转为int型
    int sum = (int) a+(int) b;

    //再将int型转为jint
    return  (jint)sum;
}

JNIEXPORT jstring JNICALL Java_com_zy_fengchun_jnidemo_JniUtils_generateNewString
        (JNIEnv * env, jobject jobj, jstring jstr){
        if (jstr == NULL)
        {
            LOGI("Your params is NULL");
            return (*env)->NewStringUTF(env,"NULL");
        }
        //jstr转为char*
        // JNI_FALSE JNI_TURE NULL 三种参数得到的String也不同
        char * data = (*env)->GetStringUTFChars(env, jstr, 0);
        char str[20] = " zhangyu";
        strcat(data,str);

        jstring new_str = (*env)->NewStringUTF(env,data);
        return new_str;

}

JNIEXPORT jstring JNICALL Java_com_zy_fengchun_jnidemo_JniUtils_generateStringFromVariable
        (JNIEnv * env, jobject jobj){
    jclass clazz = (*env)->GetObjectClass(env,jobj);
    jfieldID fid = (*env)->GetFieldID(env,clazz,"mName","Ljava/lang/String;");
    jstring jstr = (*env)->GetObjectField(env,jobj,fid);

    char * data = (*env)->GetStringUTFChars(env,jstr,0);
    char str[20] = " zoe";
    strcat(data,str);

    jstring new_jstr = (*env)->NewStringUTF(env,data);

    (*env)->SetObjectField(env, jobj, fid, new_jstr);
    return new_jstr;
    }

JNIEXPORT jstring JNICALL Java_com_zy_fengchun_jnidemo_JniUtils_accessStaticField
        (JNIEnv * env, jobject jobj){
    jclass clazz = (*env)->GetObjectClass(env,jobj);
    jfieldID fid = (*env)->GetStaticFieldID(env,clazz,"mStaticName","Ljava/lang/String;");
    jstring jstr = (*env)->GetStaticObjectField(env,clazz,fid);

    char * data = (*env)->GetStringUTFChars(env,jstr,0);
    char str[20] = "zoe";
    strcat(data,str);

    jstring new_jstr = (*env)->NewStringUTF(env,data);
    (*env)->SetStaticObjectField(env,clazz,fid,new_jstr);
    return new_jstr;
}