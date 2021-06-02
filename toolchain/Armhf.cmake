SET(CMAKE_SYSTEM_NAME Linux)
SET(TOOLCHAIN_PREFIX arm-linux-gnueabi)
if(NOT SKIP_COMPILER_VERSION)
	SET(COMPILER_VERSION 5)
	if(NOT COMPILER_VERSION MATCHES "-.*")
		SET(COMPILER_VERSION "-${COMPILER_VERSION}")
	endif()
endif()
SET(TOOLCHAIN_SUFFIX hf)
SET(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}${TOOLCHAIN_SUFFIX}-gcc${COMPILER_VERSION})
SET(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}${TOOLCHAIN_SUFFIX}-g++${COMPILER_VERSION})
SET(CMAKE_STRIP ${TOOLCHAIN_PREFIX}${TOOLCHAIN_SUFFIX}-strip CACHE FILEPATH "" FORCE)
SET(CMAKE_FIND_ROOT_PATH /usr/${TOOLCHAIN_PREFIX}${TOOLCHAIN_SUFFIX}/)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)

