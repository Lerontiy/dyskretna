#include <iostream>
#include "comb.h"
#include "../lab2/Sort.h"
using namespace std;

void lab_3_1(int k, int n) {
    //cout << factorial(k) << endl;
    //cout << factorial(n) << endl;+
    cout << "A " << A(k, n) << endl;
    cout << "_A " << _A(k, n) << endl;
    cout << "C " << C(k, n) << endl;
    cout << "_C " << _C(k, n) << endl;
}

void lab_3_2(MyArray array, int k) {
    for (int i=1; i<factorial(k); i++) {
        GenComb(array, k);
        cout << i+1 << ". ";
        array.show();
    }
}

void lab_3_3(MyArray array, int k, int n) {
    for (int i=1; i<C(k, n); i++) {
        GenPerm(array, k, n);
        cout << i+1 << ". ";
        array.show();
    }
}

int main() {
    int k = 4;
    mytype n = 6;

    mytype items[k] = {};
    for (mytype i = 0; i<k; i++) {
        items[i] = i+1;
    }
    MyArray array(items, k);
    cout << 1 << ". ";
    array.show();

    //lab_3_1(k, n);
    lab_3_2(array, k);
    //lab_3_3(array, k, n);
    
    return 0;
}
