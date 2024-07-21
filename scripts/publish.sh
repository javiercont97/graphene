#!/bin/bash
source scripts/colors.sh

##############################################
# tests
##############################################
# Read the current version from library.json
version=$(jq -r '.version' library.json)
echo -e "${CYAN}Version to be published: $version${NC}"

publishedVersion=$(pio pkg show javiercont97/Graphene | grep "^$version")

publishedDate=$(echo $publishedVersion | awk '{print $3}')
publishedTime=$(echo $publishedVersion | awk '{print $4}')
publishedDateTime="$publishedDate $publishedTime"

if [ "$publishedVersion" == "" ]; then
	pio pkg publish --no-interactive .
	echo -e "${GREEN}Version $version published successfully.${NC}"
else
	echo -e "${RED}Version $version already published on $publishedDateTime${NC}"
	echo -e "${GREEN}Skipping publish.${NC}"
fi

