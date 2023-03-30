set(SOURCE_PROJECT "${CMAKE_PROJECT_NAME}")

add_library(
    ${SOURCE_PROJECT}
        Graphs.cpp
)

target_include_directories(
    ${SOURCE_PROJECT}
    
    PUBLIC 
        ./
)
