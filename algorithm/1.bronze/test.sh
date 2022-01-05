clang++ -g3 -std=c++11 -Wall -Wextra -Werror 1085.cpp
# clang++ -g3 -fsanitize=address -Wall -Wextra -Werror 1005.cpp
# ./a.out
MallocNanoZone=0 ./a.out 
# rm -rf a.out
