rm -rf a.out
g++ -g3 -fsanitize=address main.cpp
MallocNanoZone=0 ./a.out