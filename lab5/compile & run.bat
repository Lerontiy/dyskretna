del lab5.exe && cls
g++ -c ../lab4/List.cpp -c Converter.cpp -c lab5.cpp && g++ List.o Converter.o lab5.o -o lab5 && del List.o Converter.o lab5.o && lab5.exe