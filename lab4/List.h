#include <iostream>

#ifndef Included_List_H
#define Included_List_H

typedef char datatype; 

struct Node
{
    datatype key;
    Node* next;
    Node* previous; //у випадку двозв’язного списку
};

void pushstack(datatype item);
void popstack();
void showstack();

void clear();
void add_begin(datatype item);
void add_end(datatype item);
void del_begin();
void del_end();
Node* search(datatype item);
void add_mid(datatype find, datatype item);
void del_mid(datatype find);
void showqueue();

void add_to_string(std::string &str);
void get_stack_el(std::string &res);

extern Node *headstack, *first, *last; // declaration

#endif // Included_List_H 




