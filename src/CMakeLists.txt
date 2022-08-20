
add_executable(app main.cpp
)

add_subdirectory(engine)
add_subdirectory(graphics)
add_subdirectory(game)

target_include_directories(app PRIVATE ${PROJECT_SOURCE_DIR}/include)

find_package(SFML 2 REQUIRED network audio graphics window system) 
target_include_directories(app PUBLIC ${SFML_INCLUDE_DIR}) 
target_link_libraries(app sfml-graphics)

set_target_properties(app PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/bin)
