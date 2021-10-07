cmake_minimum_required(VERSION 3.14)
project(Properties)

# set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# 定义MSVC的编译方式 ----- 下面的这个东西非常重要，是sln工程运行程序的关键
if(MSVC)
  set(
    CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} /bigobj /MP /wd4005 /wd4996 /wd4819 /wd4251 /wd4267 /wd4244 /wd4275 /wd4530 /wd4334 /wd4018 /openmp"
    )
  add_definitions(-D_ENABLE_EXTENDED_ALIGNED_STORAGE -DNOMINMAX)
  # 该命令主要是用于C/C++命令行
  add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
  add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
  add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:-openmp:llvm>")
  add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:-openmp:experimental>")
endif(MSVC)


enable_testing()
find_package(GTest REQUIRED)
# OpenMP Support
find_package(OpenMP REQUIRED)


# 关闭cmake预定义的文件夹
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 指定外部模块的路径
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# 引入cmakeHelper模块
# include(CMakeHelper)
include(SelfDefineMacro)
add_subdirectory(src)

