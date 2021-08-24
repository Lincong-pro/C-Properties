# 设置该变量的原因是可以让该层测试使用定时器
set(cherno "${CMAKE_SOURCE_DIR}/SRC/cherno tutorials")

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
    ${cherno}
  )


# 将生成的target放入到tests/下
set_target_properties(${exeName} PROPERTIES FOLDER "official/")
