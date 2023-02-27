#!/bin/bash

git add . && \
git add -u && \
git commit -m $'Routine Commit\n@arfazhxss '"$(date)"$ && \
git push origin HEAD
