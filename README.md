### This is a clone of the (buggy) JSSC-library
Cloned from https://github.com/scream3r/java-simple-serial-connector/tree/2.8.0/src/java

Our develop-branch starts from Tag "v2.8.0". This is the
latest and obvious final official release of scream3r JSSC library, dating from January 2014.

### ISA and JSSC
We use this version 2.8.0 throughout ISA for all Hardware-Services which
need Serial-I/O-communication with hardware devices.
- Vroom     *(Kundendisplay)*
- Caveman   *(Legic-Reader)*
- Loon      *(uBlox-GPS-Module)*
- Vogon     *(LSA-Transmitter)*
- Babelfish *(IBIS-Wagenbus)*
- Megacamel *(GSM-Modem)*

### The problem (= reason for this clone and fix)
We're basically fine with this library (even when it's old) - except one thing:
Sudden SIGSEGV-Container-Crashes (Java-Process dies).<br>
Analysis: [See here](https://jira.post.ch/browse/SDCISA-428?focusedCommentId=1054382&page=com.atlassian.jira.plugin.system.issuetabpanels%3Acomment-tabpanel#comment-1054382)
*(and you can find lots of more references to the SIGSEGV-Problem in ISA's Jira-Histrory)*
*(and you can find lots of more references to the SIGSEGV-Problem in ISA's Jira-Histrory)*
*(and you can find lots of more references to the SIGSEGV-Problem in ISA's Jira-Histrory)*

### This clone
- added this `README.md`
- make it a Maven-Project (i.e. added a pom.xml and move files to Maven-typical src/-directories)
- added Jenkinsfiles
- we don't create a build infrastructure for the native code (note that the original Repo doesn't contain anything concerning native build).<br>
Though we describe how to manually build the Linux-Library as we need to change code here.<br>
Windows-and Mac-Libraries are kept untouched in their binary form.

### How to build the native stuff
- We use officiall GCC docker image to compile CPP-source to the *.so shared object.
- We only need and support the 64-Bit-Linux-binary.<br>
*i.e. if you need to compile Windows-DLL or for MacOS or a 32-Bit-library: help yourself*
```
scp -rp src/ isa@eddieXXXXX:jssc/src
```
And then on that Eddie:
```
cd jssc
docker run --rm --user $(id -u):$(id -g) -v "$PWD":/blubb -w /blubb gcc:9.2.0 g++ -Isrc/main/extracted-jni-headers -fPIC -shared -o jssc.so src/main/cpp/_nix_ba sed/jssc.cpp
```
see also [README concerning JNI-header-files](src/main/extracted-jni-headers/README.md)
