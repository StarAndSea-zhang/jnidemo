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

JNIEXPORT jobject JNICALL Java_com_zy_fengchun_jnidemo_JniUtils_accessConstructor
  (JNIEnv * env, jobject jobj){
    jclass cls  = (*env)->FindClass(env,"java/util/Date");
    jmethodID constructor_mid = (*env)->GetMethodID(env,cls,"<init>","()V");

    jobject date_jobj = (*env)->NewObject(env,cls,constructor_mid);

    jmethodID mid = (*env)->GetMethodID(env,cls,"getTime","()J");
    jlong time = (*env)->CallLongMethod(env,date_jobj,mid);
    LOGE("time is %ld",time);
    return date_jobj;
  }

  JNIEXPORT void JNICALL Java_com_zy_fengchun_jnidemo_JniUtils_accessNonvirtualMethod
    (JNIEnv * env, jobject jobj){
        jclass cls = (*env)->GetObjectClass(env,jobj);
        jfieldID fid = (*env)->GetFieldID(env,cls,"mFather","Lcom/zy/fengchun/jnidemo/Father;");
        jobject fa_obj  = (*env)->GetObjectField(env,jobj,fid);

        jclass father_cls = (*env)->FindClass(env,"com/zy/fengchun/jnidemo/Father");
        jmethodID mid = (*env)->GetMethodID(env,father_cls,"sayHi","()V");
LOGE("1");
        (*env)->CallObjectMethod(env, fa_obj, mid);
LOGE("2");
//        (*env)->CallNonvirtualObjectMethod(env,fa_obj , father_cls,mid);

    }

 JNIEXPORT jstring JNICALL Java_com_zy_fengchun_jnidemo_JniUtils_chineseChars
   (JNIEnv *env, jobject jobj, jstring jstr){
    char *c_str = "陆垚知马俐";
    jclass clazz = (*env)->FindClass(env,"java/lang/String");
    jmethodID constructor_mid = (*env)->GetMethodID(env, clazz, "<init>", "([BLjava/lang/String;)V");

    jbyteArray bytes = (*env)->NewByteArray(env, strlen(c_str));
    (*env)->SetByteArrayRegion(env, bytes, 0, strlen(c_str), c_str);
    jstring charsetName = (*env)->NewStringUTF(env, "UTF-8");
    return (*env)->NewObject(env,clazz,constructor_mid,bytes,charsetName);
}

int compare(int *a,int *b){
    return (*a) - (*b);
}

JNIEXPORT jintArray JNICALL Java_com_zy_fengchun_jnidemo_JniUtils_setArray
(JNIEnv *env, jobject jobj, jintArray arr){
    jint *elems = (*env)->GetIntArrayElements(env,arr,NULL);
    int len = (*env)->GetArrayLength(env,arr);
    qsort(elems,len,sizeof(jint),compare);
    (*env)->ReleaseIntArrayElements(env,arr,elems,JNI_COMMIT);
    return arr;
}


JNIEXPORT jintArray JNICALL Java_com_zy_fengchun_jnidemo_JniUtils_getArray
        (JNIEnv *env, jobject jobj, jint len){
    jintArray jint_arr = (*env)->NewIntArray(env,len);
    jint *elems = (*env)->GetIntArrayElements(env,jint_arr,NULL);
    int i = 0;
    for(;i<len;i++){
        elems[i] = i;
    }
    (*env)->ReleaseIntArrayElements(env,jint_arr,elems,0);
    return jint_arr;
}