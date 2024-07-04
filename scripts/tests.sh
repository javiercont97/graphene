#!/bin/bash

##############################################
# colorize
##############################################

# Define colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[0;37m'
NC='\033[0m' # No Color

# Function to apply color
colorize() {
	local color=$1
	shift
	local message="$@"
	echo -e "${color}${message}${NC}"
}

##############################################
# tests
##############################################

path_to_project=$(pwd)

colorize $CYAN "--> [UNIT-TESTS] Prepare to build"
cmake -S $path_to_project -B $path_to_project/build
if [ $? -ne 0 ]; then
	colorize $RED "CMake configuration failed."
	exit 1
fi

colorize $CYAN "--> [UNIT-TESTS] Building..."
cd $path_to_project

cmake --build "$path_to_project/build" --config Debug --target all --
if [ $? -ne 0 ]; then
	colorize $RED "Build failed."
	exit 1
fi


colorize $CYAN "--> [UNIT-TESTS] Running tests..."
cd build

ctest -j18 -C Debug -T test --output-on-failure -VV -R .*
test_status=$?

if [ $test_status -ne 0 ]; then
	colorize $RED "Tests failed. Exiting with status $test_status."
	exit $test_status
else
	colorize $GREEN "All tests passed successfully."
fi
