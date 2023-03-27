include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

set(UT_PROJECT "${CMAKE_PROJECT_NAME}_UNIT_TEST")
set(SOURCE_PROJECT "${CMAKE_PROJECT_NAME}_SOURCE")

add_executable(
    ${UT_PROJECT}
        test_summing_array_template.cpp
)

target_link_libraries(
    ${UT_PROJECT}
    
    PRIVATE
        GTest::GTest
        ${SOURCE_PROJECT}
)

add_test("${SOURCE_PROJECT}_GTEST" ${UT_PROJECT})