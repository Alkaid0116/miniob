INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

FILE(GLOB_RECURSE ALL_SRC  *.cpp)

#SHARED，动态库
#STATIC，静态库
ADD_LIBRARY(common STATIC ${ALL_SRC} )


IF(USE_MUSL_LIBC)
    MESSAGE(STATUS "musl libc need manually link libexecinfo")
    TARGET_LINK_LIBRARIES(common execinfo)
ENDIF(USE_MUSL_LIBC)

TARGET_LINK_LIBRARIES(common replxx::replxx)
MESSAGE(STATUS "common uses replxx")

# 编译静态库时，自动会把同名的动态库给删除， 因此需要临时设置一下
SET_TARGET_PROPERTIES(common PROPERTIES CLEAN_DIRECT_OUTPUT 1)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

