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