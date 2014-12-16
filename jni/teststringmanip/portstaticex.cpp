#include <jni.h>
#include<stdio.h>

#include "../libstringmanip/stringmanip.h"

void showMsgs() {
	showMsg1();
	showMsg2();
	showMsg3();
	showMsg4();
	showMsg5();
	showMsg6();
	showMsg7();
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *pvm, void *reserved) {
	JNIEnv *env;
	if (pvm->GetEnv((void **) &env, JNI_VERSION_1_6)) {
		return -1;
	}
	JNINativeMethod jm[1];
	jm[0].name = "showMsgs";
	jm[0].signature = "()V";
	jm[0].fnPtr = (void *) showMsgs;

	jclass clz = (env)->FindClass("com/dastan/portstaticex/MainActivity");
	env->RegisterNatives(clz, jm, 1);

	return JNI_VERSION_1_6;
}

