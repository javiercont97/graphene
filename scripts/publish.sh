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
# Read the current version from library.json
version=$(jq -r '.version' library.json)
colorize $CYAN "Version to be published: $version"

publishedVersion=$(pio pkg show javiercont97/Graphene | grep "^$version")

publishedDate=$(echo $publishedVersion | awk '{print $3}')
publishedTime=$(echo $publishedVersion | awk '{print $4}')
publishedDateTime="$publishedDate $publishedTime"

if [ "$publishedVersion" == "" ]; then
	pio pkg publish --no-interactive .
	colorize $GREEN "Version $version published successfully."
else
	colorize $RED "Version $version already published on $publishedDateTime"
	colorize $GREEN "Skipping publish."
fi

