LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := stringmanipulation
LOCAL_SRC_FILES := stringmanipulation.cpp
LOCAL_LDLIBS	:= -llog 

include $(BUILD_STATIC_LIBRARY)
