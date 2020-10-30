#!/bin/sh

git branch -D svgs || exit
git branch svgs || exit
git checkout svgs || exit

for DIR in comp10002/pattern_search/ comp10002/
do
    cd "$DIR" || exit
    for FILE in *.md
    do
        echo "Rendering $FILE"
        python -m readme2tex "$FILE" --output "$FILE" --nocdn
    done
done
