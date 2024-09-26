#include <iostream>
#include "Sort.h"

using namespace std;

// template <typename mytype>
MyArray::MyArray(const mytype* elems, int n1, int n2, int n3) : size(n1), start(n2), end(n3) {
    elements = new mytype[size];
    for (int i = 0; i < size; i++) {
        elements[i] = elems[i];
    }
}

// template <typename mytype>
void MyArray::swap(mytype* a, mytype* b){
    mytype temp = *a;
    *a = *b;
    *b = temp;
}

// template <typename mytype>
void MyArray::show(){
    for (int i=0; i<size; i++){
        cout << elements[i] << " ";
    }
    cout << endl;
}

// template <typename mytype>
void MyArray::SortBubble(int start, int end){
    int sorted_size = 0;
    bool praporec;
    int iterations = 0;

    while (sorted_size<end) {
        praporec = true;
        for (int i=start+1; i<end-sorted_size; i++) {
            if (elements[i-1] > elements[i]) {
                swap(&elements[i-1], &elements[i]);
                praporec = false;
            }
            iterations++;
        }
        if (praporec){
            break;
        }
        sorted_size++;
    }

    cout << "ітерацій: " << iterations << " ";
}

// template <typename mytype>
int MyArray::MaxItem(int start, int end, int& iterations){
    int max = start;
    for (int i=start; i<end; i++){
        if (elements[i] > elements[max]) {
            max = i;
        }
        iterations++;
    }
    return max;
}

// template <typename mytype>
int MyArray::MinItem(int start, int end, int& iterations){
    int min = start;
    for (int i=start; i<end; i++){   
        if (elements[i] < elements[min]) {
            min = i;
        }
        iterations++;
    }
    return min;
}

// template <typename mytype>
void MyArray::SortSelection(int start, int end){
    int start_sort = start;
    int min;
    int iterations = 0;

    while (start_sort < end) {
        min = MinItem(start_sort, end, iterations);
        swap(&elements[start_sort], &elements[min]);
        start_sort++;
    } 

    cout << "ітерацій: " << iterations << " ";    
}

// template <typename mytype>
void MyArray::SortInsertion(int start, int end){
    int iterations = 0;
    int sorted_size = 1;
    int temp_i = 0;

    for (int i = start+1; i<end; i++) {
        temp_i = i;
        iterations++;
        for (int temp_i = i; temp_i>0 && elements[temp_i-1] > elements[temp_i]; temp_i--){
            swap(&elements[temp_i], &elements[temp_i-1]);
            iterations++;
        }
    }

    cout << "ітерацій: " << iterations << " ";    
}

