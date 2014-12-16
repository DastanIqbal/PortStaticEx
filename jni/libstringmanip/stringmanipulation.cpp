#include<jni.h>
#include<stdio.h>
#include<string.h>
#include<android/log.h>

#include "stringmanip.h"

jstring stringManipulate(JNIEnv *env, jobject jobj, jstring jstr) {

	//Java String
	__android_log_print(ANDROID_LOG_INFO, "PortSharedEx",
			"Java String UTF-16 %s", &jstr);

	//JNI String
	const char *str;
	jboolean *iscopy;
	str = env->GetStringUTFChars(jstr, iscopy);
	__android_log_print(ANDROID_LOG_INFO, "PortSharedEx",
			"IsCopy %d JNI String UTF-8 %s", iscopy, str);

	//JNI String Length
	jsize length = env->GetStringUTFLength(jstr);
	__android_log_print(ANDROID_LOG_INFO, "PortSharedEx",
			"JNI String UTF-8 length %d==%d ", length, strlen(str));
	__android_log_print(ANDROID_LOG_INFO, "PortSharedEx",
			"JNI String UTF-8 ends with %d  %d", str[length], str[length + 1]);
	//Release Java and JNI String
	env->ReleaseStringUTFChars(jstr, str);

	//Copied Java string to Buffer
	char nativestr[100];
	env->GetStringUTFRegion(jstr, 0, length, nativestr);
	__android_log_print(ANDROID_LOG_INFO, "PortSharedEx",
			"converted to UTF-8 jstring copied to native buffer %s", nativestr);

	//JNI UTF-8 String and Length
	const char *newstr = "hello 安卓";
	jstring ret = env->NewStringUTF(newstr);
	jsize lenght = env->GetStringUTFLength(ret);
	__android_log_print(ANDROID_LOG_INFO, "PortSharedEx",
			"JNI String %s and length %d=%d", newstr, lenght, strlen(newstr));
	return ret;
}

void showMsg1() {
	__android_log_print(ANDROID_LOG_INFO, "PortSharedEx", "Message Method 1");

}

void showMsg2() {
	__android_log_print(ANDROID_LOG_INFO, "PortSharedEx", "Message Method 2");

}
void showMsg3() {
	__android_log_print(ANDROID_LOG_INFO, "PortSharedEx", "Message Method 3");

}
void showMsg4() {
	__android_log_print(ANDROID_LOG_INFO, "PortSharedEx", "Message Method 4");

}
void showMsg5() {
	__android_log_print(ANDROID_LOG_INFO, "PortSharedEx", "Message Method 5");

}
void showMsg6() {
	__android_log_print(ANDROID_LOG_INFO, "PortSharedEx", "Message Method 6");

}
void showMsg7() {
	__android_log_print(ANDROID_LOG_INFO, "PortSharedEx", "Message Method 7");

}

/*
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {

	JNIEnv *env;

	if ((vm)->GetEnv((void **) &env, JNI_VERSION_1_6)) {
		return -1;
	}

	JNINativeMethod jm[1];
	jm[0].name = "stringManipulate";
	jm[0].signature = "(Ljava/lang/String;)Ljava/lang/String;";
	jm[0].fnPtr = (void *) stringManipulate;

	jclass clz = env->FindClass("com/dastan/portsharedex/MainActivity");
	env->RegisterNatives(clz, jm, 1);
	return JNI_VERSION_1_6;

}
*/
