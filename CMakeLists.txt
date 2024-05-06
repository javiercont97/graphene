cmake_minimum_required(VERSION 3.12)
project(Graphene)

# Set the C++ standard to gnu++2a
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the source files for the library
set(SOURCES
	src/Graphene.h
	
	# Core files
	src/core/Color.h
	src/core/Color.cpp
	src/core/Object.h
	src/core/Object.cpp
	src/core/Point.h
	src/core/Point.cpp
	src/core/String.h
	src/core/String.cpp
	src/core/Variant.h
	
	# Geometry files
	# src/geometry/Geometry.h
	
	# driver files
	src/driver/Screen.h
	src/driver/Screen.cpp
	src/driver/FrameBuffer.h
	src/driver/FrameBuffer.cpp
)

# Create the static library
add_library(Graphene STATIC ${SOURCES})

# Include directories for the library
target_include_directories(Graphene PUBLIC include)

# Set up unit tests with Unity
enable_testing()
add_subdirectory(tests)


# Format the code using clang-format
find_program(CLANG_FORMAT_EXECUTABLE clang-format)
if(CLANG_FORMAT_EXECUTABLE)
	file(GLOB_RECURSE ALL_SOURCE_FILES
		${CMAKE_SOURCE_DIR}/src/*.cpp
		${CMAKE_SOURCE_DIR}/include/*.h
		${CMAKE_SOURCE_DIR}/tests/*.cpp
	)
	add_custom_target(format
		COMMAND ${CLANG_FORMAT_EXECUTABLE} -i ${ALL_SOURCE_FILES}
		COMMENT "Formatting code using clang-format"
	)
endif()