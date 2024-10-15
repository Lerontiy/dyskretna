prompt $g 
g++ -c ../lab1/LogCon.cpp -c ../lab2/sort.cpp -c comb.cpp -c lab3.cpp 
g++ LogCon.o sort.o comb.o lab3.o -o lab3 
del LogCon.o comb.o lab3.o sort.o 
lab3.exe && pause