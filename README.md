
# Jssc (PaISA fork)

A small, single Java library for working with serial ports based on the work
from [scream3r/java-simple-serial-connector](https://github.com/scream3r/java-simple-serial-connector).


## See also

- [README about jni headers](src/main/cpp/extracted-jni-headers/README.md)
- [README @ upstream](https://github.com/java-native/jssc/blob/master/README.md).


## Build shared lib (native part)

In PaISA we only had a need to patch the linux binary. The other binaries are
not re-compiled, as I see no need to do so yet. I only kept the precompiled
libs which we most probably use. Linux on prod, win (and maybe osx) for local
development.

To perform the build, I used this (bash) script below. Basically just squashed
all the commands from oli together so I didn't have to execute all of them
manually every time.

```
#!/bin/bash

# Configure
set -e
SSH_USER=$USERNAME
BUILD_HOST=TODO_CHOOSE_YOUR_EDDIE

# Prepare build for native lib.
if [ "`git diff HEAD --exit-code`" ]; then
    echo "[WARN ] Git working-tree not clean! Burned-in version will be inaccurate.";
fi
echo '#define JSSC_VERSION "'`(git describe --tags|sed 's,^v,,')`'"' > src/main/cpp/version.h
ssh ${SSH_USER}@${BUILD_HOST} -- "if [" -e jssc-build "] ;then echo '[ERROR] Remote build dir already exists (you have to cleanup your remote first)'; exit 1; else mkdir -p jssc-build/src/main/cpp; fi"
scp -rp src/main/cpp ${SSH_USER}@${BUILD_HOST}:jssc-build/src/main/.

# Actually build native lib
ssh ${SSH_USER}@${BUILD_HOST} -- cd jssc-build "&&" mkdir -p src/main/resources-precompiled/natives/linux_64 "&&" sudo docker run --rm --user '$(id -u):$(id -g)' -v '"$PWD"':/blubb -w /blubb gcc:4.8 g++ -Wall -pedantic -Werror -Wno-error=long-long -Wno-error=sign-compare -Isrc/main/cpp/extracted-jni-headers -Isrc/main/cpp -fPIC -shared -o src/main/resources-precompiled/natives/linux_64/libjssc.so src/main/cpp/_nix_based/jssc.cpp

# Copy back result into our local worktree. And cleanup on remote.
scp -r ${SSH_USER}@${BUILD_HOST}:jssc-build/src .
ssh $BUILD_HOST -- rm jssc-build -rf

# Complete the build by creating the final jar.
mvn verify
```
