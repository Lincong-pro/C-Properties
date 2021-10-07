file(GLOB SOURCES "*.cpp" "*.hpp" "*.h")
# 得到当前文件夹的名字
get_dirctory_name(exeName) 
add_executable(
  ${exeName}
  ${SOURCES}
)
# 链接添加当前文件夹以便于包含头文件
target_include_directories(${exeName}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

target_link_libraries(
  ${exeName}  PRIVATE 
    GTest::GTest 
    GTest::Main
    OpenMP::OpenMP_CXX
)

# 设置编译器编译的规则-openmp
target_compile_options(${exeName}
  PUBLIC
    ${OpenMP_CXX_FLAGS}
  )
# 将生成的target放入到tests/下
set_target_properties(${exeName} PROPERTIES FOLDER "official/" LINK_FLAGS ${OpenMP_CXX_FLAGS})