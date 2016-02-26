#!/bin/sh




find  . -type f -name '*.h' | xargs sed -i 's/<mongoc\.h>/"mongoc\.h"/g'
#find  . -type f -name '*.h' | xargs sed -i 's/"mongoc\.h"/"\/home\/xiao\/libmongoc-1\.0\/mongoc\.h"/g'


find  . -type f -name '*.h' | xargs sed -i 's/<bson\.h>/"bson\.h"/g'
#find  . -type f -name '*.h' | xargs sed -i 's/"bson\.h"/"\/home\/xiao\/libbson-1\.0\/bson\.h"/g'
