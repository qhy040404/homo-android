#include "iostream"
#include "homo.h"
#include <jni.h>

using namespace std;
const int N = 32;
int n, a[N];
bool isFirst= true;
string s[N] = {"", "11/(45-1)*4", "-11+4-5+14", "-11-4+5+14", "11-4+5/1-4", "11-4-5+14", "1*1+45-14", "11*4+5*1*4", "1+1+(4+5)*14", "(114-51)*4+(-11-4+5+14)", "1+1-4+514", "1*(1+4)*51*4+(-11-4+5+14)", "-11+4*514+(11*-4+51-4)", "(1+1)*451*4+(11*(45-1)+4)", "114*5*14+((1+1)*4+51*4)", "1145*14+((11-4)*51-4+(11/(45-1)*4))", "114*51*4+((1+1)*4514+(11*45-14+(11*-4+51-4)))", "114*514+(11*45*14+(-11/4+51/4))", "114514+(1145*14+(1*14+514))", "114514*(-11+4-5+14)+(114*51*4+((1+1)*4514+(11+4*51*4+(11-4*5+14))))", "114514*(-11-4+5+14)+(114*514+(1+14*514+((1+145)*-(1-4)+(11/(45-1)*4))))", "114514*(11-4+5+1-4)+(1145*14+((11+451)*4+(-1-1+4+5*14)))", "114514*(1+1+4*5*1-4)+(114*51*4+(11451+4+(1145+14+(1*-1+45-14))))", "114514*(11+4*5+1+4)+(114*514+(11451+4+(114*-5*(1-4)+(-11+45+1+4))))", "114514*(1*14*5-1+4)+(114*51*4+(114*51+4+(-11+4+5+14)))", "114514*(11+45*-(1-4))+(11*4514+(114*5*14+(1+14+514+(11-4+5+1-4))))", "114514*(11+4*5*14+(-11+4-5+14))+(114*(5-1)*4+(1-14+5+14))", "114514*(114*5+14+(-11+4-5+14))+((1+1)*451*4+(11+45/1-4))", "114514*(1145+14+(1*14-5/1+4))+(1+14*514+(114-5+14))", "114514*(114*5*1*4+(11*4+5*1*4))+(1+14514+(-1-14*(5-14)))", "114514*((1145+1)*4+(114-5-1-4))+(114*51*4+(114*51+4+(11*4*5-14)))", "114514*((1+1)*4514+(11*(45-14)+(11-4+5-1-4)))+(11*4514+(114*5*14+(-(1-14)*5*14+(11-4-5+14))))"};
string Homo::print(int x){
    string rData;
    if (isFirst){
        isFirst= false;
    } else{
        if (s[x][0]!='-') rData="+";
    }
    rData+=s[x];
    return s[x];
}
string Homo::BinarySplit(int x){
    for (int i = 30; i >=0 ; i--)
        if ((1<<i)&x)
            return print(i+1);
    return "null";
}

jstring charTojstring(JNIEnv* env, const char* pat) {
    jclass strClass = (env)->FindClass("java/lang/String");
    jmethodID ctorID = (env)->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    jbyteArray bytes = (env)->NewByteArray(strlen(pat));
    (env)->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte*) pat);
    jstring encoding = (env)->NewStringUTF("GB2312");
    return (jstring) (env)->NewObject(strClass, ctorID, bytes, encoding);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_qhy040404_homo_MainActivity_00024Companion_BinarySplit(JNIEnv *env, jobject thiz, jint x) {
    Homo homo = Homo();
    string data = homo.BinarySplit(x);
    return charTojstring(env,data.c_str());
}