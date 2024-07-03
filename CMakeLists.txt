cmake_minimum_required(VERSION 3.12)
project(Graphene)

# Set the C++ standard to gnu++2a
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable/Disable Graphene features
add_definitions(-DENABLE_GRAPHENE_IMAGE_FORMAT)
# add_definitions(-DENABLE_STM32F769I_DRIVERS)
# add_definitions(-DENABLE_NODEMCU_DRIVERS)

# Add the source files for the library
set(SOURCES
	src/Graphene.h

	# Interface files
	src/interfaces/AbstractCanvas.h
	src/interfaces/AbstractCanvas.cpp
	src/interfaces/AbstractTouchInput.h
	src/interfaces/AbstractTouchInput.cpp

	src/interfaces/IDrawable.h
	src/interfaces/IContainer.h
	src/interfaces/IContainer.cpp
	src/interfaces/IWidget.h
	src/interfaces/IWidget.cpp
	
	# Core files
	src/core/Color.h
	src/core/Color.cpp
	src/core/Object.h
	src/core/Object.cpp
	src/core/String.h
	src/core/String.cpp
	src/core/Variant.h
	src/core/Font.h
	src/core/Font.cpp
	
	# Math files
	src/math/Point.h
	src/math/Point.cpp
	src/math/Vector3D.h
	src/math/Vector3D.cpp
	src/math/Rect.h
	src/math/Rect.cpp

	# Image files
	src/image/Image.h
	src/image/Image.cpp
	
	# components
	src/components/layouts/HorizontalLayout.h
	src/components/layouts/HorizontalLayout.cpp
	src/components/layouts/VerticalLayout.h
	src/components/layouts/VerticalLayout.cpp

	src/components/widgets/Label.h
	src/components/widgets/Label.cpp
	src/components/widgets/Button.h
	src/components/widgets/Button.cpp

	# events
	src/events/TouchEvent.h

	# drivers
	src/drivers/STM32F769I/STM32F769I_Canvas.h
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
