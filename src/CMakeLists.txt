# project or target
project(netease2017_01)
set(netease2017_01_srcs
        netease/p2017_01.cpp)

# shared use_library
add_library(netease2017_01 SHARED ${netease2017_01_srcs})
SET_TARGET_PROPERTIES(netease2017_01 PROPERTIES CLEAN_DIRECT_OUTPUT 1)
# static use_library
add_library(netease2017_01_static STATIC ${netease2017_01_srcs})
SET_TARGET_PROPERTIES(netease2017_01_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)


# sub directory
add_subdirectory(leetcode)
add_subdirectory(netease)
add_subdirectory(offer)
add_subdirectory(liurujia)
add_subdirectory(ali)
add_subdirectory(bytedance)
add_subdirectory(tzx20190810)
add_subdirectory(20190811)
add_subdirectory(tzx20190823)
add_subdirectory(quicksort-iteration)
add_subdirectory(threepots)
add_subdirectory(endian)
add_subdirectory(tzx20190904)
add_subdirectory(tzx20190907)
add_subdirectory(tzx20190918)
add_subdirectory(tencent20190920)
add_subdirectory(tzxdsl20190921)