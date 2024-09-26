#include <iostream>
#include <cmath>
#include "sort.h"

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

int GenPerm(int[] A, int n){

}