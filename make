if [ -f main ]
then
rm main
fi

clang++ -std=c++17 -o main ./src/main.cpp

if [ -f main ]
then
./main
rm main
fi
