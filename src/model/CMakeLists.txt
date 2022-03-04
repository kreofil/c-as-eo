# set minimum cmake version
cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

#set(BUILD_DIR "${CMAKE_BINARY_DIR}")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
  # headers
  eo_objects.h
  tags.h
  ext_tags.h
  poly.h
  fibonacci.h

  #sources
  main.c
  eo_objects.c
  poly.c
  fibonacci.c
)

add_executable(c-as-eo ${SOURCE_FILES})
