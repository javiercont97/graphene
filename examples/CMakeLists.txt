# Checkerboard
add_executable(checkerboard_demo canvas_demo/checkerboard_demo.cpp)
target_link_libraries(checkerboard_demo Graphene)
target_include_directories(checkerboard_demo PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Import/export
add_executable(read_and_re_export_demo canvas_demo/read_and_re_export_demo.cpp)
target_link_libraries(read_and_re_export_demo Graphene)
target_include_directories(read_and_re_export_demo PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Trigonometric functions
add_executable(trigonometric canvas_demo/trigonometric.cpp)
target_link_libraries(trigonometric Graphene)
target_include_directories(trigonometric PRIVATE ${CMAKE_SOURCE_DIR}/src)

# # Minecraft creeper
add_executable(creeper canvas_demo/creeper.cpp)
target_link_libraries(creeper Graphene)
target_include_directories(creeper PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Canvas demo usage examples
add_executable(image_demo canvas_demo/image_demo.cpp)
target_link_libraries(image_demo Graphene)
target_include_directories(image_demo PRIVATE ${CMAKE_SOURCE_DIR}/src)

# String usage examples
add_executable(string_demo string_demo/string_demo.cpp)
target_link_libraries(string_demo Graphene)
target_include_directories(string_demo PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Vector demo usage examples
add_executable(vector_demo vectors_demo/vector_demo.cpp)
target_link_libraries(vector_demo Graphene)
target_include_directories(vector_demo PRIVATE ${CMAKE_SOURCE_DIR}/src)
