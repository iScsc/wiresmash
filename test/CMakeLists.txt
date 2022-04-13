
add_executable(testApp test.cpp
                  ../src/engine/universe_master.cpp
)

target_include_directories(testApp PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(testApp ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

set_target_properties(testApp PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/bin)
