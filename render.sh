#!/bin/sh

git branch -D svgs || exit
git branch svgs || exit
git checkout svgs || exit

cd comp10002/pattern_search/ || exit
python -m readme2tex README.md  --output README.md --nocdn
python -m readme2tex bmh.md  --output bmh.md --nocdn
python -m readme2tex bwt.md  --output bwt.md --nocdn
python -m readme2tex kmp.md  --output kmp.md --nocdn
python -m readme2tex naive-search.md  --output naive-search.md --nocdn
python -m readme2tex suffix-arrays.md  --output suffix-arrays.md --nocdn