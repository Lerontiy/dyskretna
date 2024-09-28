#include <iostream>
#include "comb.h"
#include "../lab2/Sort.h"
using namespace std;


void lab_3_1(int k, int n) {
    cout << factorial(k) << endl;
    cout << factorial(n) << endl;
    cout << A(k, n) << endl;
    cout << _A(k, n) << endl;
    cout << C(k, n) << endl;
    cout << _C(k, n) << endl;
}

void lab_3_2(int SIZE, int MAXITEM) {
    mytype items[SIZE] = {};
    for (int i = 0; i<SIZE; i++) {
        items[i] = i+1;
    }
    MyArray array(items, SIZE);
    cout << 1 << ". ";
    array.show();
    for (int i=1; i<C(SIZE, MAXITEM); i++) {
        GenPerm(array, MAXITEM);
        cout << i+1 << ". ";
        array.show();
    }
}


int main(){
    int SIZE = 4;
    mytype MAXITEM = 6;

    //lab_3_1(SIZE, MAXITEM);
    lab_3_2(SIZE, MAXITEM);
    
    return 0;
}
