cmake_minimum_required(VERSION 3.5)

project(THREAD_POOL,VERSION 1.0)

aux_source_directory(${PROJECT_SOURCE_DIR}/src)
aux_source_directory(${PROJECT_SOURCE_DIR}/test)

include_directories(
  ${PROJECT_SOURCE_DIR}/include
)

link_directories(
  ${PROJECT_SOURCE_DIR}/lib
)