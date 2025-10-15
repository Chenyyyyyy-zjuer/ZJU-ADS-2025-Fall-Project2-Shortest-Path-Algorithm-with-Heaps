cmake_minimum_required(VERSION 3.10.0)
project(project2 VERSION 0.1.0 LANGUAGES C CXX)


# bin 目录下存最后生成的可执行文件
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 将源码文件.cpp的目录保存在SRC_LIST变量
aux_source_directory (src SRC_LIST)

include(CTest)
enable_testing()

if(MSVC)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

#add_executable(main ${SRC_LIST})

#target_link_libraries(test_max gtest_main)

#add_test(NAME test_max COMMAND test_max)