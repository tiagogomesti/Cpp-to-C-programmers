include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(
    state_machine_test 
        test.cpp
)

target_link_libraries(
    state_machine_test
    
    PRIVATE
        GTest::GTest
        state_machine
)

add_test(state_machine_gtest state_machine_test)