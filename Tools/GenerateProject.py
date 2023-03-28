import sys
import os

def check_parent_folder(parent_folder):
    if not os.path.exists(parent_folder):
        print("Error: Parent folder don't exists")
        exit(1)

def create_folders(folder_path):
    if not os.path.exists(folder_path):
        os.mkdir(folder_path)

def write_project_cmakelists_file(path, project_name):
    file = path + '/' + "CMakeLists.txt"
    with open(file, 'w') as f:
        f.write("cmake_minimum_required(VERSION 3.16)\n")
        f.write("\n")
        f.write("project(\n")
        f.write("    %s\n" % project_name)
        f.write(")\n")
        f.write("\n")
        f.write("set(CMAKE_CXX_STANDARD 17)\n")
        f.write("\n")
        f.write("enable_testing()\n")
        f.write("add_subdirectory(src)\n")
        f.write("add_subdirectory(test)\n")

def write_src_cmakelists_file(path, project_name):
    file = path + '/' + "CMakeLists.txt"
    with open(file, 'w') as f:
        f.write("set(SOURCE_PROJECT \"${CMAKE_PROJECT_NAME}\")\n")
        f.write("\n")
        f.write("add_library(\n")
        f.write("    ${SOURCE_PROJECT}\n")
        f.write("        %s.cpp\n" % project_name)
        f.write(")\n")
        f.write("\n")
        f.write("target_include_directories(\n")
        f.write("    ${SOURCE_PROJECT}\n")
        f.write("    \n")
        f.write("    PUBLIC \n")
        f.write("        ./\n")
        f.write(")\n")

def write_src_code_files(path, project_name):
    file = path + '/' + project_name + ".cpp"
    with open(file, 'w') as f: 
        f.write("#include \"%s.h\"\n" % project_name)
        f.write("\n")
        f.write("int %s(void)\n" % project_name)
        f.write("{\n")
        f.write("    return 0;\n")
        f.write("}\n")      

    file = path + '/' + project_name + ".h"
    with open(file, 'w') as f:  
        f.write("#ifndef %s_H\n" % project_name.upper())
        f.write("#define %s_H\n" % project_name.upper())
        f.write("\n")
        f.write("int %s(void);\n" % project_name)
        f.write("\n")
        f.write("#endif\n")

def write_test_cmakelists_file(path, project_name):
    file = path + '/' + "CMakeLists.txt"
    with open(file, 'w') as f:
        f.write("include(FetchContent)\n")
        f.write("\n")
        f.write("FetchContent_Declare(\n")
        f.write("    googletest\n")
        f.write("    GIT_REPOSITORY https://github.com/google/googletest.git\n")
        f.write("    GIT_TAG        release-1.11.0\n")
        f.write(")\n")
        f.write("FetchContent_MakeAvailable(googletest)\n")
        f.write("add_library(GTest::GTest INTERFACE IMPORTED)\n")
        f.write("target_link_libraries(GTest::GTest INTERFACE gtest_main)\n")
        f.write("\n")
        f.write("set(UT_PROJECT \"${CMAKE_PROJECT_NAME}_ut\")\n")
        f.write("set(SOURCE_PROJECT \"${CMAKE_PROJECT_NAME}\")\n")
        f.write("\n")
        f.write("add_executable(\n")
        f.write("    ${UT_PROJECT}\n")
        f.write("        %s_ut.cpp\n" % project_name)
        f.write(")\n")
        f.write("\n")
        f.write("target_link_libraries(\n")
        f.write("    ${UT_PROJECT}\n")
        f.write("    \n")
        f.write("    PRIVATE\n")
        f.write("        GTest::GTest\n")
        f.write("        ${SOURCE_PROJECT}\n")
        f.write(")\n")
        f.write("\n")
        f.write("add_test(\"${SOURCE_PROJECT}_gtest\" ${UT_PROJECT})\n")

def write_test_code_file(path, project_name):
    file = path + '/' + project_name + "_ut.cpp"
    with open(file, 'w') as f: 
        f.write("#include <gtest/gtest.h>\n")
        f.write("#include <%s.h>\n" % project_name)
        f.write("\n")
        f.write("TEST(%sTest, AssertTrue)\n" % project_name)
        f.write("{\n")
        f.write("    ASSERT_TRUE(%s() == 0);\n" % project_name)
        f.write("}\n")
        f.write("\n")
        f.write("TEST(%sTest, AssertFalse)\n" % project_name)
        f.write("{\n")
        f.write("    ASSERT_FALSE(%s() != 0);\n" % project_name)
        f.write("}\n")
        f.write("\n")
        f.write("\n")
        f.write("int main(int argc, char **argv)\n")
        f.write("{\n")
        f.write("    testing::InitGoogleTest(&argc, argv);\n")
        f.write("    return RUN_ALL_TESTS();\n")
        f.write("}\n")

def main():
    if len(sys.argv) != 3:
        print("Necessary 2 parameters (Typed %d)" % (len(sys.argv)-1))
        print("\t$1: Project's parent folder (must exist)")
        print("\t$2: Project's name")
        exit(1)

    parent_folder = sys.argv[1]
    project_name = sys.argv[2]

    if project_name == "project":
        print("Project name isn't allowed")

    check_parent_folder(parent_folder)
    
    project_folder = parent_folder + '/' + project_name
    create_folders(project_folder)
    write_project_cmakelists_file(project_folder, project_name)
    
    src_folder = project_folder + '/src'
    create_folders(src_folder)
    write_src_cmakelists_file(src_folder, project_name)
    write_src_code_files(src_folder, project_name)
    
    test_folder = project_folder + '/test'
    create_folders(test_folder)
    write_test_cmakelists_file(test_folder, project_name)
    write_test_code_file(test_folder, project_name)

if __name__ == "__main__":
    main()
