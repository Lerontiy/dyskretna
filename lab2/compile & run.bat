prompt $g
g++ -c Sort.cpp -c Lab2.cpp
g++ Sort.o Lab2.o -o Lab2 
del Sort.o Lab2.o 
cls && Lab2.exe && pause

