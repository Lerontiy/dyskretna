#include <iostream>
#include "Sort.h"

using namespace std;


MyArray::MyArray(mytype* elems, int n1) : size(n1) {
    elements = new mytype[size];
    for (int i = 0; i < size; i++) {
        elements[i] = elems[i];
    }
}

void MyArray::swap(int i1, int i2){
    mytype temp = elements[i1];
    elements[i1] = elements[i2];
    elements[i2] = temp;
}

void MyArray::show(){
    for (int i=0; i<size; i++){
        cout << elements[i] << " ";
    }
    cout << endl;
}

void MyArray::SortBubble(int start, int end){
    int sorted_size = 0;
    bool praporec;
    int iterations = 0;

    while (sorted_size<end) {
        praporec = true;
        for (int i=start+1; i<end-sorted_size; i++) {
            if (elements[i-1] > elements[i]) {
                //cout << i-1 << " " << i << ", ";
                swap(i-1, i);
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

void MyArray::SortSelection(int start, int end){
    int start_sort = start;
    int min;
    int iterations = 0;

    while (start_sort < end) {
        min = MinItem(start_sort, end, iterations);
        swap(start_sort, min);
        start_sort++;
    } 

    cout << "ітерацій: " << iterations << " ";    
}

void MyArray::SortInsertion(int start, int end){
    int iterations = 0;
    int sorted_size = 1;
    int temp_i = 0;

    for (int i = start+1; i<end; i++) {
        temp_i = i;
        iterations++;
        for (int temp_i = i; temp_i>0 && (elements[temp_i-1] > elements[temp_i]); temp_i--){
            swap(temp_i, temp_i-1);
            iterations++;
        }
    }

    cout << "ітерацій: " << iterations << " ";    
}

