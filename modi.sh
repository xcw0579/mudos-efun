#!/bin/bash




find  . -type f -name '*.c' | xargs sed -i 's/P1(\(.*\),\(.*\))/(\1 \2)/g'

find  . -type f -name '*.c' | xargs sed -i 's/P2(\(.*\),\(.*\),\(.*\),\(.*\))/(\1 \2,\3 \4)/g'

find  . -type f -name '*.c' | xargs sed -i 's/P3(\(.*\),\(.*\),\(.*\),\(.*\),\(.*\),\(.*\))/(\1 \2,\3 \4,\5 \6)/g'

find  . -type f -name '*.c' | xargs sed -i 's/P4(\(.*\),\(.*\),\(.*\),\(.*\),\(.*\),\(.*\),\(.*\),\(.*\))/(\1 \2,\3 \4,\5 \6,\7 \8)/g'


# 去掉PROT
find  . -type f -name '*.c' | xargs sed -i 's/PROT((\(.*\)))/(\1)/g'

