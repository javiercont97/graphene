#!/bin/bash

# install git hooks
cp scripts/hooks/pre-commit .git/hooks/pre-commit
chmod +x .git/hooks/pre-commit

cp scripts/hooks/prepare-commit-msg .git/hooks/prepare-commit-msg
chmod +x .git/hooks/prepare-commit-msg

cp scripts/hooks/pre-push .git/hooks/pre-push
chmod +x .git/hooks/pre-push