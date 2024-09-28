#include <cmath>
#include "../lab2/Sort.h"

using namespace std;

int factorial(int n){
    if (n>1) {
        //cout << n << endl;
        n *= factorial(n-1);
    }else {
        return 1;
    }
    return n;
}

int A(int k, int n){
    return factorial(n) / factorial(n-k);
}

int _A(int k, int n){
    return pow(n, k);
}

int C(int k, int n){
    return A(k, n) / factorial(k);
}

int _C(int k, int n){
    return C(k, n+k-1);
}

void GenPerm(MyArray A, mytype n){
    for (int i=A.size; i>=0; i--) {
        if (A.elements[i-1] != n-A.size+i) {
            A.elements[i-1]++;
            for (int ii=i; ii<=A.size; ii++) {
                A.elements[ii] = A.elements[ii-1] + 1;
            }
            break;
        }
    }
}
