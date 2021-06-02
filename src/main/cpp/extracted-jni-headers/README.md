### Noted about the two jni-Header-files

To compile JNI you need (next to a C/C++ compiler) a JDK installed.
With the JDK you
1. can create the header-files (from a Java-Class which contains `native` methods)
2. get additional headers which are required to compile your C/C++ code - especially `jni.h` and a platform-specific `jni_md.h`

To ease compile-process for this JSSC-library those two files are expracted from a JDK and placed in the src/-folder.<br>
To regenerate the files use:

```
docker run --rm docker.io/oracle/openjdk:8 cat /usr/lib/jvm/java-1.8.0-openjdk-1.8.0.242.b08-0.el7_7.x86_64/include/jni.h > jni.h
docker run --rm docker.io/oracle/openjdk:8 cat /usr/lib/jvm/java-1.8.0-openjdk-1.8.0.242.b08-0.el7_7.x86_64/include/linux/jni_md.h > jni_md.h
```

For jdk11 I used:
```
docker run --rm openjdk:11 cat /usr/local/openjdk-11/include/jni.h > jni.h
docker run --rm openjdk:11 cat /usr/local/openjdk-11/include/linux/jni_md.h > jni_md.h
```
