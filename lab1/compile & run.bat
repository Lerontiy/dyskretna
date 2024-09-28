prompt $g
g++ -c LogCon.cpp -c Lab_1.cpp
g++ LogCon.o Lab_1.o -o Lab_1
del LogCon.o Lab_1.o
cls && Lab_1.exe && pause
