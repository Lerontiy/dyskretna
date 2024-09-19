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
    //MyArray<mytype> array1(items, size, start, end);    
    //MyArray<mytype> array2(items, size, start, end);    

    SetConsoleOutputCP(CP_UTF8); // вивід до консолі українських літер
    
    cout << "невідсортований список: ";
    array.show();

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

    return 0;
}
