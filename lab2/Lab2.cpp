#include <iostream>
#include "Sort.h"
#include <windows.h>
using namespace std;

int main() {
    mytype array[] = {9, 0, 4, 5, 3, 8};
    mytype array1[] = {9, 0, 4, 5, 3, 8};
    mytype array2[] = {9, 0, 4, 5, 3, 8};
    int size = sizeof(array) / sizeof(array[0]);

    SetConsoleOutputCP(CP_UTF8); // вивід до консолі укріїнських літер

    cout << "невідсортований список: ";
    show(array, size);

    //for (int i=size-1; i>=0; i--){array[i] = size-1-i;}
    SortBubble(array, size);
    cout << "сортування бульбашкою: ";
    show(array, size);

    //for (int i=size-1; i>=0; i--){array[i] = size-1-i;}
    SortSelection(array1, size);
    cout << "сортування вибором: ";
    show(array1, size);

    //for (int i=size-1; i>=0; i--){array[i] = size-1-i;}
    SortInsertion(array2, size);
    cout << "сортування вставкою: ";
    show(array2, size);

    return 0;
}