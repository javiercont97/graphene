add_executable(core_test
	# core specs
    core/Color.spec.h
	core/Object.spec.h
	core/String.spec.h
	core/Variant.spec.h

	# core test files
	core/GrapheneCore.spec.cpp
)
target_include_directories(core_test PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(core_test PRIVATE Graphene unity)
add_test(NAME core_test COMMAND core_test)


add_executable(math_test
	# core specs
    math/Point.spec.h

	# core test files
	math/GrapheneMath.spec.cpp
)
target_include_directories(math_test PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(math_test PRIVATE Graphene unity)
add_test(NAME math_test COMMAND math_test)


# add_executable(driver_test
# 	# driver specs
# 	driver/FrameBuffer.spec.h
# 	driver/VirtualScreenDriver.spec.h

# 	# driver test files
# 	driver/GrapheneDriver.spec.cpp
# )

# target_include_directories(driver_test PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Link against the Graphene library and Unity test framework
# target_link_libraries(driver_test PRIVATE Graphene unity)

# Add the tests as a target
# # add_test(NAME driver_test COMMAND driver_test)


# Coverage configuration
if(CODE_COVERAGE)
    foreach(test_target core_test math_test)
        target_compile_options(${test_target} PUBLIC --coverage -O0)
        target_link_libraries(${test_target} PUBLIC --coverage)
    endforeach()

    find_program(LCOV lcov)
    find_program(GENHTML genhtml)

    if(LCOV AND GENHTML)
        add_custom_target(coverage
            COMMAND ${LCOV} --capture --directory . --output-file coverage.info
            COMMAND ${LCOV} --remove coverage.info '/usr/*' --output-file coverage.info
            COMMAND ${LCOV} --list coverage.info
            COMMAND ${GENHTML} coverage.info --output-directory out
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            COMMENT "Generating coverage report"
        )
        
        add_custom_target(check_coverage
            COMMAND ${LCOV} --capture --directory . --output-file coverage.info
            COMMAND ${LCOV} --remove coverage.info '/usr/*' --output-file coverage.info
            COMMAND ${LCOV} --list coverage.info
            COMMAND ${LCOV} --summary coverage.info | awk '/lines/{print $$2}' | awk -F. '{if ($$1 < 85) exit 1}'
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            COMMENT "Checking coverage"
        )

		add_custom_target(coverage_html
			COMMAND ${GENHTML} coverage.info -t "Graphene coverage report" -f --output-directory coverage_report
			WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
			COMMENT "Generating coverage report in HTML"
		)
    endif()
endif()