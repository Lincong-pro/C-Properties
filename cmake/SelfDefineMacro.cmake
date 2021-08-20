# 获取某个文件夹下所有的文件夹
MACRO(SUBDIRLIST result curdir)
  # 宏名字为SUBDIRLIST 参数为result（返回） curdir（传入）
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  # 创建字符串集合
  SET(dirlist "")
  # FOREACH遍历每一个文件夹放入结果集中
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  # 赋值给返回参数
  SET(${result} ${dirlist})
ENDMACRO()

# 无参数的宏定义
# 利用上面的宏定义一个更便捷的宏直接add_subdirectory所有的文件夹
MACRO(add_subdirectorys)
    # 调用函数（函数在主CMakeLists文件中已经引用）
    SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
    foreach(sampledir ${SUBDIRS})
        add_subdirectory(${sampledir})
    endforeach()
ENDMACRO()


# 得到当前文件夹的名字
macro(get_dirctory_name result)
    get_filename_component(DirName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    string(REPLACE " " "_" DirName ${DirName})
    set(${result} ${DirName})
endmacro()
