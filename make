# if [ -f main ]
# then
# rm main
# fi

# META
ARG_NUM=4

# FLAGS
RESET_FLAG="--reset"
RUN_OLD_BINARY_FLAG="--old"
RUN_NEW_BINARY_FLAG="--new"

# FILE STRUCTURE
ROOT=./
BINARY_FILENAME=${ROOT}bin/
OUTPUT_FILENAME=${ROOT}out/
COMPILED_BINARY=${BINARY_FILENAME}compiled

# ERROR MESSAGES
ERROR_ARG_NUM="incorrect number of arguments... aborting"
ERROR_NO_COMPILED_BINARY="no old compiled binary... aborting"

if [ ! -d ${BINARY_FILENAME} ]
then
    mkdir ${BINARY_FILENAME}
fi

if [ ! -d ${OUTPUT_FILENAME} ]
then
    mkdir ${OUTPUT_FILENAME}
fi

if [ $1 = ${RESET_FLAG} ]
then
    X="ls -a | wc -l"
    C=$X
    if [[ $C -gt 2 ]]
    then
        rm ${BINARY_FILENAME}*
    fi
    exit 0
fi

if [ $# -ne ${ARG_NUM} ]
then
    echo ${ERROR_ARG_NUM}
    exit 1
fi

if [ $1 = ${RUN_OLD_BINARY_FLAG} ]
then
    if [ -f ${COMPILED_BINARY} ]
    then
        ${COMPILED_BINARY} $2 $3 $4
    else
        echo ${ERROR_NO_COMPILED_BINARY}
        exit 1
    fi
fi

if [ $1 = ${RUN_NEW_BINARY_FLAG} ]
then
    # ROOT=./

    SRC=${ROOT}src/

    META=${SRC}meta/
    OBJECTS=${SRC}objects/
    MAIN_C=${SRC}main.cpp

    INIT=${META}init/
    RAY=${META}ray/
    VEC3=${META}vec3/

    INIT_C=${INIT}init.cpp
    RAY_C=${RAY}ray.cpp
    VEC3_C=${VEC3}vec3.cpp
    VEC3_UTILS_C=${VEC3}vec3_utils.cpp

    HITRECORD=${OBJECTS}hit_record/
    HITTABLE=${OBJECTS}hittable/
    HITTABLE_LIST=${OBJECTS}hittable_list/
    SPHERE=${OBJECTS}sphere/

    HITRECORD_C=${HITRECORD}hit_record.cpp
    HITTABLE_C=${HITTABLE}hittable.cpp
    HITTABLE_LIST_C=${HITTABLE_LIST}hittable_list.cpp
    SPHERE_C=${SPHERE}sphere.cpp

    clang++ -std=c++17 -o compiled $MAIN_C $INIT_C $VEC3_C $VEC3_UTILS_C $RAY_C $HITRECORD_C $HITTABLE_C $HITTABLE_LIST_C $SPHERE_C

    if [ -f ${COMPILED_BINARY} ]
    then
        mv compiled ${BINARY_FILENAME}
        ${COMPILED_BINARY} $2 $3 $4
    fi
fi
