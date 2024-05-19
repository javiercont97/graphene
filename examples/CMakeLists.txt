# Frame buffer to PPM P6 image
add_executable(FrameBufferToPPM FrameBufferToPPM.cpp)
target_link_libraries(FrameBufferToPPM Graphene)
target_include_directories(FrameBufferToPPM PRIVATE ${CMAKE_SOURCE_DIR}/src)