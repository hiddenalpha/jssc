SET(CMAKE_SYSTEM_NAME Linux)
SET(TOOLCHAIN_PREFIX aarch64-linux-gnu)
SET(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}-gcc)
SET(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}-g++)
SET(CMAKE_STRIP ${TOOLCHAIN_PREFIX}-strip CACHE FILEPATH "" FORCE)
SET(CMAKE_FIND_ROOT_PATH /usr/${TOOLCHAIN_PREFIX}/)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)

