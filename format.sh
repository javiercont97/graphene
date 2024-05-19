#!/bin/bash

# format source code
find src -name '*.cpp' -exec clang-format -i {} \;
find src -name '*.h' -exec clang-format -i {} \;

# format test code
find tests -name '*.cpp' -exec clang-format -i {} \;
find tests -name '*.h' -exec clang-format -i {} \;

# format example code
find examples -name '*.cpp' -exec clang-format -i {} \;
find examples -name '*.h' -exec clang-format -i {} \;
