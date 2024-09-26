#include <iostream>
#include "Sort.h"
#include <windows.h>
#include <cstdlib>

using namespace std;

int main() {
    const int SIZE = 2000;
    mytype items[SIZE] = {};  

    
    for (int i = SIZE; i >= 0; i--) {
        items[i] = rand();
    }

    //mytype items[] = {9, 0, 4, 5, 3, 8};
    int size = sizeof(items) / sizeof(items[0]);

    int start = 0;
    int end = size;

    MyArray array(items, size, start, end);    
    MyArray array1(items, size, start, end);    
    MyArray array2(items, size, start, end);    

    SetConsoleOutputCP(CP_UTF8); // вивід до консолі українських літер
    
    //cout << "невідсортований список: ";
    //array.show();

    array.SortBubble(start, end);
    cout << "сортування бульбашкою: ";
    cout << endl;
    //array.show();

    array1.SortSelection(start, end);
    cout << "сортування вибором: ";
    cout << endl;
    //array1.show();

    array2.SortInsertion(start, end);
    cout << "сортування вставкою: ";
    cout << endl;
    //array2.show();

    /*
    int type;
    cout << "Оберіть спосіб сортування (1-бульбашка 2-вибір 3-вставка): ";
    cin >> type;

    switch (type){
        case 1:
            array.SortBubble(start, end);
            cout << "сортування бульбашкою: ";
            array.show();
            break;
        case 2:
            array.SortSelection(start, end);
            cout << "сортування вибором: ";
            array.show();
            break;
        case 3:
            array.SortInsertion(start, end);
            cout << "сортування вставкою: ";
            array.show();
            break;
        default:
            cout << "невідомий спосіб" << endl;
    }
    */

    return 0;
}
