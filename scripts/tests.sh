#!/bin/bash
source scripts/colors.sh

##############################################
# tests
##############################################

path_to_project=$(pwd)

echo -e "${CYAN}--> [UNIT-TESTS] Prepare to build${NC}"
cmake -DCODE_COVERAGE=ON -S $path_to_project -B $path_to_project/build
if [ $? -ne 0 ]; then
	echo -e "${RED}CMake configuration failed.${NC}"
	exit 1
fi

echo -e "${CYAN}--> [UNIT-TESTS] Building...${NC}"
cd $path_to_project

cmake --build "$path_to_project/build" --config Debug --target all --
if [ $? -ne 0 ]; then
	echo -e "${RED}Build failed.${NC}"
	exit 1
fi


echo -e "${CYAN}--> [UNIT-TESTS] Running tests...${NC}"
cd build

ctest -C Debug -T test --output-on-failure -VV -R .*
test_status=$?

if [ $test_status -ne 0 ]; then
	echo -e "${RED}Tests failed. Exiting with status $test_status.${NC}"
	exit $test_status
fi

echo -e "${GREEN}All tests passed successfully.${NC}"

echo -e "${CYAN}--> [UNIT-TESTS] Run coverage checks...${NC}"
make coverage
if [ $? -ne 0 ]; then
	echo -e "${RED}Coverage report generation failed.${NC}"
	exit 1
fi

echo -e "${CYAN}--> [UNIT-TESTS] Check coverage target percentage is met...${NC}"

make check_coverage
if [ $? -ne 0 ]; then
	echo -e "${RED}Coverage target percentage is not met. (Threshold: 85%)${NC}"
	exit 1
fi

echo -e "${GREEN}Coverage target percentage is met.${NC}"

make coverage_html
if [ $? -ne 0 ]; then
	echo -e "${RED}Coverage report generation failed.${NC}"
	exit 1
fi

echo -e "${GREEN}Coverage report generated successfully.${NC}"
