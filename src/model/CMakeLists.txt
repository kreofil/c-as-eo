# set minimum cmake version
cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

#set(BUILD_DIR "${CMAKE_BINARY_DIR}")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
  # headers
  tags.h
  eo_any.h
  eo_int.h
  eo_double.h
  eo_seq.h
  fibonacci.h

  #sources
  main.c
  eo_any.c
  eo_int.c
  eo_double.c
  eo_seq.c
  fibonacci.c
)

add_executable(c-as-eo ${SOURCE_FILES})
