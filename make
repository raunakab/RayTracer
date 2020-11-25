if [ -f main ]
then
rm main
fi

ROOT=./

SRC=${ROOT}src/

INIT=${SRC}init/
OBJECTS=${SRC}objects/
RAY=${SRC}ray/
VEC3=${SRC}vec3/
MAIN_C=${SRC}main.cpp

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

clang++ -std=c++17 -o main $MAIN_C $INIT_C $VEC3_C $VEC3_UTILS_C $RAY_C $HITRECORD_C $HITTABLE_C $HITTABLE_LIST_C $SPHERE_C

if [ -f main ]
then
if [ ! -d out ]
then
mkdir ./out/
fi
./main $1 $2 $3
rm main
fi
