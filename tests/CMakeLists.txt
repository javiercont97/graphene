add_executable(core_test
    core/Color.spec.h
	core/Object.spec.h
	core/Point.spec.h
	core/String.spec.h
	core/Variant.spec.h

	Graphene.spec.cpp
    # Add more test files as needed
)

target_include_directories(core_test PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Link against the Graphene library and Unity test framework
target_link_libraries(core_test PRIVATE Graphene unity)

# Add the tests as a target
add_test(NAME core_test COMMAND core_test)
