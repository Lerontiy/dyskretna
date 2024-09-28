#include <iostream>


using namespace std;

typedef int mytype;

#ifndef MYARRAY_H
#define MYARRAY_H

//template <typename mytype>
class MyArray {
    private:
        mytype* elements;
        int size;
        void swap(mytype* a, mytype* b);
        int MinItem(int start, int end, int& iterations);
        int MaxItem(int start, int end, int& iterations);
    public:
        MyArray(const mytype* elems, int n1, int n2, int n3);
        int start;
        int end;

        void show();
        void SortBubble(int start, int end);
        void SortSelection(int start, int end);
        void SortInsertion(int start, int end);
};

#endif

//#include "Sort.cpp"
