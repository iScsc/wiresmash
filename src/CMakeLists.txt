
add_executable(app main.cpp
)

add_subdirectory(engine)

target_include_directories(app PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(app ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

set_target_properties(app PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/bin)
