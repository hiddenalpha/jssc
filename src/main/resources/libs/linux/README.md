We don't support all versions of the Linux-libs
as we 1. don't need them and 2. have no build/compile infrastructure

Removed:
- libjSSC_armhf.so
- libjSSC_armsf.so
- libjSSC_x86.so

So we only support, need and therefor build/compile the 64-Bit-Linux-Library:
- libjSSC_x86_64.so

see [ths README](../../../../../README.md) for details of how to build this single library