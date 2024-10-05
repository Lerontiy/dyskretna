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

void GenComb(MyArray A, int k, bool reverse){
    if (reverse) {
        for (int i=1; i<k; i++) {
            if (A.elements[i-1] > A.elements[i]) {
                int temp = i-1;
                for (int ii=0; ii<i; ii++) {
                    if ((A.elements[i] < A.elements[ii]) && (A.elements[ii] < A.elements[temp])) {
                        temp = ii;
                    }
                }
                A.swap(i, temp);
                A.SortInsertion(0, i, reverse);
                return;
            }
        }
    } else {
        for (int i=k-1; i>0; i--) {
            if (A.elements[i-1] < A.elements[i]) {
                int temp = i;
                for (int ii=temp+1; ii<k; ii++) {
                    if ((A.elements[i-1] < A.elements[ii]) && (A.elements[ii] < A.elements[temp])) {
                        temp = ii;
                    }
                }
                A.swap(i-1, temp);
                A.SortInsertion(i, k, reverse);
                return;
            }
        }
    }
}

void GenPerm(MyArray A, int k, int n, bool reverse){
    for (int i=k; i>0; i--) {
        if (reverse) {
            if (A.elements[i-1] != k-i+1) {
                A.elements[i-1]--;
                for (int ii=i; ii<k; ii++) {
                    A.elements[ii] = A.elements[ii-1] - 1;
                }
                return;
            }
        } else {
            if (A.elements[i-1] != n-k+i) {
                A.elements[i-1]++;
                for (int ii=i; ii<=k; ii++) {
                    A.elements[ii] = A.elements[ii-1] + 1;
                }
                return;
            }
        }
    }
}