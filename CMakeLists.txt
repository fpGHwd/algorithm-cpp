cmake_minimum_required(VERSION 3.2)
project(beauty_in_code)
set(CMAKE_CXX_STANDARD 14)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/netease
        /usr/local/include
        /usr/include
)

link_directories(
        ${PROJECT_BINARY_DIR}/lib
        /usr/local/lib
        /usr/lib
)

#add_executable(netease2017-01 src/netease/netease2017-01.cpp src/offer/string-p42.cpp)
#target_link_libraries(netease2017-01 m)

# delete for important understanding and not store
# https://blog.csdn.net/hebbely/article/details/79169965
# https://blog.csdn.net/ShawnAtCSDB/article/details/78785602

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(unittests)