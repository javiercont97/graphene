# Frame buffer to PPM image
add_executable(FrameBufferToPPM FrameBufferToPPM.cpp)
target_link_libraries(FrameBufferToPPM Graphene)
target_include_directories(FrameBufferToPPM PRIVATE ${CMAKE_SOURCE_DIR}/src)


# Checkerboard
add_executable(CheckerBoard CheckerBoard.cpp)
target_link_libraries(CheckerBoard Graphene)
target_include_directories(CheckerBoard PRIVATE ${CMAKE_SOURCE_DIR}/src)


# Trigonometric functions
add_executable(Trigonometric Trigonometric.cpp)
target_link_libraries(Trigonometric Graphene)
target_include_directories(Trigonometric PRIVATE ${CMAKE_SOURCE_DIR}/src)
