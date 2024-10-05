#include <iostream>


using namespace std;

typedef int mytype;

#ifndef MYARRAY_H
#define MYARRAY_H

//template <typename mytype>
class MyArray {
    public:
        MyArray(mytype* elems, int n1);
        mytype* elements;
        int size;

        void show();
        void swap(int i1, int i2);
        int MinItem(int start, int end, int& iterations);
        int MaxItem(int start, int end, int& iterations);
        void SortBubble(int start, int end);
        void SortSelection(int start, int end);
        void SortInsertion(int start, int end, bool reverse);
};

#endif

//#include "Sort.cpp"
