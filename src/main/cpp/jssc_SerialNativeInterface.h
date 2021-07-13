/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class jssc_SerialNativeInterface */

#ifndef _Included_jssc_SerialNativeInterface
#define _Included_jssc_SerialNativeInterface
#ifdef __cplusplus
extern "C" {
#endif
#undef jssc_SerialNativeInterface_OS_LINUX
#define jssc_SerialNativeInterface_OS_LINUX 0L
#undef jssc_SerialNativeInterface_OS_WINDOWS
#define jssc_SerialNativeInterface_OS_WINDOWS 1L
#undef jssc_SerialNativeInterface_OS_SOLARIS
#define jssc_SerialNativeInterface_OS_SOLARIS 2L
#undef jssc_SerialNativeInterface_OS_MAC_OS_X
#define jssc_SerialNativeInterface_OS_MAC_OS_X 3L
#undef jssc_SerialNativeInterface_ERR_PORT_BUSY
#define jssc_SerialNativeInterface_ERR_PORT_BUSY -1LL
#undef jssc_SerialNativeInterface_ERR_PORT_NOT_FOUND
#define jssc_SerialNativeInterface_ERR_PORT_NOT_FOUND -2LL
#undef jssc_SerialNativeInterface_ERR_PERMISSION_DENIED
#define jssc_SerialNativeInterface_ERR_PERMISSION_DENIED -3LL
#undef jssc_SerialNativeInterface_ERR_INCORRECT_SERIAL_PORT
#define jssc_SerialNativeInterface_ERR_INCORRECT_SERIAL_PORT -4LL
/*
 * Class:     jssc_SerialNativeInterface
 * Method:    getNativeLibraryVersion
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_jssc_SerialNativeInterface_getNativeLibraryVersion
  (JNIEnv *, jclass);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    openPort
 * Signature: (Ljava/lang/String;Z)J
 */
JNIEXPORT jlong JNICALL Java_jssc_SerialNativeInterface_openPort
  (JNIEnv *, jobject, jstring, jboolean);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    setParams
 * Signature: (JIIIIZZI)Z
 */
JNIEXPORT jboolean JNICALL Java_jssc_SerialNativeInterface_setParams
  (JNIEnv *, jobject, jlong, jint, jint, jint, jint, jboolean, jboolean, jint);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    purgePort
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_jssc_SerialNativeInterface_purgePort
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    closePort
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_jssc_SerialNativeInterface_closePort
  (JNIEnv *, jobject, jlong);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    setEventsMask
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_jssc_SerialNativeInterface_setEventsMask
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    getEventsMask
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_jssc_SerialNativeInterface_getEventsMask
  (JNIEnv *, jobject, jlong);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    waitEvents
 * Signature: (J)[[I
 */
JNIEXPORT jobjectArray JNICALL Java_jssc_SerialNativeInterface_waitEvents
  (JNIEnv *, jobject, jlong);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    setRTS
 * Signature: (JZ)Z
 */
JNIEXPORT jboolean JNICALL Java_jssc_SerialNativeInterface_setRTS
  (JNIEnv *, jobject, jlong, jboolean);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    setDTR
 * Signature: (JZ)Z
 */
JNIEXPORT jboolean JNICALL Java_jssc_SerialNativeInterface_setDTR
  (JNIEnv *, jobject, jlong, jboolean);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    readBytes
 * Signature: (JI)[B
 */
JNIEXPORT jbyteArray JNICALL Java_jssc_SerialNativeInterface_readBytes
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    writeBytes
 * Signature: (J[B)Z
 */
JNIEXPORT jboolean JNICALL Java_jssc_SerialNativeInterface_writeBytes
  (JNIEnv *, jobject, jlong, jbyteArray);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    getBuffersBytesCount
 * Signature: (J)[I
 */
JNIEXPORT jintArray JNICALL Java_jssc_SerialNativeInterface_getBuffersBytesCount
  (JNIEnv *, jobject, jlong);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    setFlowControlMode
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_jssc_SerialNativeInterface_setFlowControlMode
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    getFlowControlMode
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_jssc_SerialNativeInterface_getFlowControlMode
  (JNIEnv *, jobject, jlong);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    getSerialPortNames
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_jssc_SerialNativeInterface_getSerialPortNames
  (JNIEnv *, jobject);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    getLinesStatus
 * Signature: (J)[I
 */
JNIEXPORT jintArray JNICALL Java_jssc_SerialNativeInterface_getLinesStatus
  (JNIEnv *, jobject, jlong);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    sendBreak
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_jssc_SerialNativeInterface_sendBreak
  (JNIEnv *, jobject, jlong, jint);

#ifdef __cplusplus
}
#endif
#endif