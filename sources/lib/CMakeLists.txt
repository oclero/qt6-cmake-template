set(LIB_NAME SomeLib)

qt_add_library(${LIB_NAME} STATIC 
  ${CMAKE_CURRENT_SOURCE_DIR}/include/SomeLib/SomeLibFile.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/SomeLibFile.cpp
)
add_library(example::${LIB_NAME} ALIAS ${LIB_NAME})

target_link_libraries(${LIB_NAME} PRIVATE Qt6::Core)

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
