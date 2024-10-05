#include <iostream>
#include "Sort.h"
#include <windows.h>
//#include <cstdlib>

using namespace std;

int main() {
    const int size = 6;

    //mytype items[size] = {};  
    //for (int i = size; i >= 0; i--) {
    //    items[i] = rand();
    //}

    mytype items[] = {6, 5, 4, 3, 2, 1};
    
    int start = 1;
    int end = size;

    MyArray array(items, size);    
    MyArray array1(items, size);    
    MyArray array2(items, size);    

    SetConsoleOutputCP(CP_UTF8); // вивід до консолі українських літер
    
    cout << "невідсортований список: ";
    array.show();

    array.SortBubble(start, end);
    cout << "сортування бульбашкою: ";
    cout << endl;
    array.show();

    array1.SortSelection(start, end);
    cout << "сортування вибором: ";
    cout << endl;
    array1.show();

    array2.SortInsertion(start, end);
    cout << "сортування вставкою: ";
    cout << endl;
    array2.show();

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
