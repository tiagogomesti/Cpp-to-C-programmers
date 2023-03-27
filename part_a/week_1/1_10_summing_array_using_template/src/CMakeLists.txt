set(SOURCE_PROJECT "${CMAKE_PROJECT_NAME}_SOURCE")

add_library(
    ${SOURCE_PROJECT}
    summing_array_template.cpp
)

target_include_directories(
    ${SOURCE_PROJECT}
    
    PUBLIC 
        ./
)