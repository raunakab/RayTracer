if [ -f main ]
then
rm main
fi

clang++ -std=c++17 -o main ./src/main.cpp ./src/vec3/vec3.cpp ./src/vec3/vec3_utils.cpp ./src/ray/ray.cpp

if [ -f main ]
then
if [ ! -d out ]
then
mkdir ./out/
fi
./main $1 $2 $3
rm main
fi
