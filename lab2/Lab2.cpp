#include <iostream>
#include "Sort.h"
#include <windows.h>

using namespace std;

int main() {
    mytype items[] = {9, 0, 4, 5, 3, 8};
    int size = sizeof(items) / sizeof(items[0]);

    int start = 0;
    int end = size;

    MyArray<mytype> array(items, size, start, end);    
    MyArray<mytype> array1(items, size, start, end);    
    MyArray<mytype> array2(items, size, start, end);    

    SetConsoleOutputCP(CP_UTF8); // вивід до консолі укріїнських літер

    cout << "невідсортований список: ";
    array.show();

    array.SortBubble(start, end);
    cout << "сортування бульбашкою: ";
    array.show();

    array1.SortSelection(start, end);
    cout << "сортування вибором: ";
    array1.show();

    array2.SortInsertion(start, end);
    cout << "сортування вставкою: ";
    array2.show();

    return 0;
}