#!/bin/sh

# since GitHub README doesn't render LaTeX math expressions properly, we instead
# resort to converting all LaTeX to svg.
# using: https://github.com/leegao/readme2tex

git branch -D svgs || exit
git branch svgs || exit
git checkout svgs || exit

SCRIPT=$(readlink -f "$0")
# Absolute path this script is in, thus /home/user/bin
SCRIPTPATH=$(dirname "$SCRIPT")
for DIR in comp10002/pattern_search/ comp10002/
do
    cd "$SCRIPTPATH" || exit
    cd "$DIR" || exit
    for FILE in *.md
    do
        echo "Rendering $FILE"
        python -m readme2tex "$FILE" --output "$FILE" --nocdn
    done
done
