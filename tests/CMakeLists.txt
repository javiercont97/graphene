add_executable(core_test
	# core specs
    core/Color.spec.h
	core/Object.spec.h
	core/Point.spec.h
	core/String.spec.h
	core/Variant.spec.h

	# core test files
	core/GrapheneCore.spec.cpp
)

add_executable(driver_test
	# driver specs
	driver/FrameBuffer.spec.h
	driver/VirtualScreenDriver.spec.h

	# driver test files
	driver/GrapheneDriver.spec.cpp
)

target_include_directories(core_test PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_include_directories(driver_test PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Link against the Graphene library and Unity test framework
target_link_libraries(core_test PRIVATE Graphene unity)
target_link_libraries(driver_test PRIVATE Graphene unity)

# Add the tests as a target
add_test(NAME core_test COMMAND core_test)
add_test(NAME driver_test COMMAND driver_test)
