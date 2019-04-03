add_executable(test unittest_google/test.cpp)
target_link_libraries(test gtest;pthread)
