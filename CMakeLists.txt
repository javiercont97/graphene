cmake_minimum_required(VERSION 3.12)
project(Graphene)

# Set the C++ standard to gnu++2a
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Graphene image format
add_definitions(-DENABLE_GRAPHENE_IMAGE_FORMAT)

# Add the source files for the library
set(SOURCES
	src/Graphene.h

	# Interface files
	src/interfaces/AbstractCanvas.h
	src/interfaces/AbstractCanvas.cpp
	
	
	# Core files
	src/core/Color.h
	src/core/Color.cpp
	src/core/Object.h
	src/core/Object.cpp
	src/core/String.h
	src/core/String.cpp
	src/core/Variant.h
	
	# Math files
	src/math/Point.h
	src/math/Point.cpp
	src/math/Vector3D.h
	src/math/Vector3D.cpp
	# src/math/Matrix.h
	# src/math/Matrix.cpp
	# src/math/Quaternion.h
	# src/math/Quaternion.cpp
	# src/math/Transform.h
	# src/math/Transform.cpp
	# src/math/Vector2D.h
	# src/math/Vector2D.cpp
	# src/math/Vector3D.h
	# src/math/Vector3D.cpp
	# src/math/Vector4D.h
	# src/math/Vector4D.cpp


	# Image files
	src/image/Image.h
	src/image/Image.cpp
	
	# Geometry files
	# src/geometry/Geometry.h
	
	# driver files
	# src/driver/VirtualScreenDriver.h
	# src/driver/VirtualScreenDriver.cpp
	# src/driver/FrameBuffer.h
	# src/driver/FrameBuffer.cpp
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



# Build examples
add_subdirectory(examples)
