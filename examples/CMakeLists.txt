# Checkerboard
add_executable(checkerboard_demo canvas_demo/checkerboard_demo.cpp)
target_link_libraries(checkerboard_demo Graphene)
target_include_directories(checkerboard_demo PRIVATE ${CMAKE_SOURCE_DIR}/src)


# # Trigonometric functions
# add_executable(Trigonometric Trigonometric.cpp)
# target_link_libraries(Trigonometric Graphene)
# target_include_directories(Trigonometric PRIVATE ${CMAKE_SOURCE_DIR}/src)


# # Minecraft creeper
# add_executable(Creeper Creeper.cpp)
# target_link_libraries(Creeper Graphene)
# target_include_directories(Creeper PRIVATE ${CMAKE_SOURCE_DIR}/src)


# # Minecraft Pillager
# add_executable(Pillager Pillager.cpp)
# target_link_libraries(Pillager Graphene)
# target_include_directories(Pillager PRIVATE ${CMAKE_SOURCE_DIR}/src)


# String usage examples
add_executable(string_demo string_demo/string_demo.cpp)
target_link_libraries(string_demo Graphene)
target_include_directories(string_demo PRIVATE ${CMAKE_SOURCE_DIR}/src)


# Vector demo usage examples
add_executable(vector_demo vectors_demo/vector_demo.cpp)
target_link_libraries(vector_demo Graphene)
target_include_directories(vector_demo PRIVATE ${CMAKE_SOURCE_DIR}/src)


# Canvas demo usage examples
add_executable(image_demo canvas_demo/image_demo.cpp)
target_link_libraries(image_demo Graphene)
target_include_directories(image_demo PRIVATE ${CMAKE_SOURCE_DIR}/src)