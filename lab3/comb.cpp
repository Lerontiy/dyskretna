#include <cmath>
#include "../lab2/Sort.h"
#include "comb.h"

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

void GenPerm(MyArray A, int k, int n){
    for (int i=k; i>=0; i--) {
        if (A.elements[i-1] != n-k+i) {
            A.elements[i-1]++;
            for (int ii=i; ii<=k; ii++) {
                A.elements[ii] = A.elements[ii-1] + 1;
            }
            return;
        }
    }
}

void GenComb(MyArray A, int k){
    for (int i=k-2; i>=0; i--) {
        if (A.elements[i] < A.elements[i+1]) {
            int temp = i+1;
            for (int ii=i+1; ii<k; ii++) {
                if ((A.elements[i] < A.elements[ii]) && (A.elements[ii] < A.elements[temp])) {
                    temp = ii;
                }
            }
            A.swap(i, temp);
            A.SortInsertion(i+1, k);
            return;
        }
    }
}
