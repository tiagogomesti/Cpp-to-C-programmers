set(SOURCE_PROJECT "${CMAKE_PROJECT_NAME}_SOURCE")

add_library(
    ${SOURCE_PROJECT}
        swap.cpp
)

target_include_directories(
    ${SOURCE_PROJECT}
    
    PUBLIC 
        ./
)