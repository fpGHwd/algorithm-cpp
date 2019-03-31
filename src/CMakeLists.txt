# project or target
project(netease2017_01)
set(netease2017_01_srcs
        netease/netease2017_01.cpp)

# shared library
add_library(netease2017_01 SHARED ${netease2017_01_srcs})
SET_TARGET_PROPERTIES(netease2017_01 PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# static library
add_library(netease2017_01_static STATIC ${netease2017_01_srcs})
SET_TARGET_PROPERTIES(netease2017_01_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
