cmake_minimum_required(VERSION 3.16)

project(
    "The Fil Rouge"
  VERSION
  1.0
  LANGUAGES
  CXX
)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(app ${SRC_FILES})
target_include_directories(app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
find_package(SFML 2 REQUIRED network audio graphics window system) 
target_include_directories(app PUBLIC ${SFML_INCLUDE_DIR}) 
target_link_libraries(app sfml-graphics)
