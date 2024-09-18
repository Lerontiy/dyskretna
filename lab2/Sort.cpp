#include "Sort.h"
#include <iostream>
using namespace std;

void show(mytype* array, int size){
    for (int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void swap(mytype* a, mytype* b){
    mytype temp = *a;
    *a = *b;
    *b = temp;

}

void SortBubble(mytype* array, int size){
    int sorted_size = 0;
    bool praporec;
    int iterations = 0;

    while (sorted_size<size) {
        praporec = true;
        for (int i=1; i<size-sorted_size; i++) {
            if (array[i-1] > array[i]) {
                swap(&array[i-1], &array[i]);
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
void SortSelection(mytype* array, int size){
    int start = 0;
    int min;
    int iterations = 0;

    while (start < size) {
        min = start;
        for (int i=start; i<size; i++){
            if (array[i] < array[min]) {
                min = i;
            }
            iterations++;
        }
        swap(&array[start], &array[min]);
        start++;
    } 

    cout << "ітерацій: " << iterations << " ";    
}

void SortInsertion(mytype* array, int size){
    int iterations = 0;
    int sorted_size = 1;
    int temp_i = 0;

    for (int i = 1; i<size; i++) {
        temp_i = i;
        for (int temp_i = i; temp_i>0 && array[temp_i-1] > array[temp_i]; temp_i--){
            swap(&array[temp_i], &array[temp_i-1]);
            iterations++;
        }
    }

    cout << "ітерацій: " << iterations << " ";    
}
