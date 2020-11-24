if [ -f main ]
then
rm main
fi

clang++ -std=c++17 -o main ./src/main.cpp ./src/vec3/vec.cpp

if [ -f main ]
then
./main
rm main
fi
