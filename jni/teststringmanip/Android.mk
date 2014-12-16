LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := portstaticex
LOCAL_C_INCLUDES:=$(LOCAL_PATH)/../libstringmainp/
LOCAL_SRC_FILES := portstaticex.cpp
LOCAL_STATIC_LIBRARIES:=stringmanipulation
LOCAL_LDLIBS:= -llog

include $(BUILD_SHARED_LIBRARY)
