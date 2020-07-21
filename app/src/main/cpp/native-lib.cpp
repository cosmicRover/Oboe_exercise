#include <jni.h>
#include <string>

#include <oboe/Oboe.h>
#include "MyCallback.h"

MyCallback myCallback;

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_oboe_1app_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    ///init an oboe builder
    oboe::AudioStreamBuilder builder;
    ///fix callback
    MyCallback myCallback;

    builder.setPerformanceMode(oboe::PerformanceMode::LowLatency)
            ->setSharingMode(oboe::SharingMode::Exclusive)
            ->setCallback(myCallback)
            ->setFormat(oboe::AudioFormat::Float);

    return env->NewStringUTF(hello.c_str());
}


