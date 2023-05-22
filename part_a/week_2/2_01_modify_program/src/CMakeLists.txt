set(SOURCE_PROJECT "${CMAKE_PROJECT_NAME}")

add_executable(
    ${SOURCE_PROJECT}
        modify_program.cpp
)

target_include_directories(
    ${SOURCE_PROJECT}
    
    PUBLIC 
        ./
)
