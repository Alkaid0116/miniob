# 可以获取父cmake的变量
MESSAGE("${CMAKE_COMMON_FLAGS}")

find_package(GTest CONFIG REQUIRED)

include(GoogleTest)

ADD_SUBDIRECTORY(common)
ADD_SUBDIRECTORY(oblsm)

IF (WITH_MEMTRACER)
    ADD_SUBDIRECTORY(memtracer)
ENDIF (WITH_MEMTRACER)

ADD_SUBDIRECTORY(observer)
