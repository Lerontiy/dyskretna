#include <iostream>
#include "List.h"

Node *headstack, *first, *last;


void pushstack(datatype item) {
    Node *temp = new Node;
    temp->key = item;
    temp->next = headstack;
    headstack = temp;
}

void popstack() {
    if (headstack == NULL) {
        std::cout << "Error: Stack is empty" << std::endl;
        return;
    }
    headstack = headstack->next;
}

void showstack() {
    Node *temp = new Node;
    temp = headstack;
    std::cout << "Stack: ";
    while (temp != NULL) {
        std::cout << temp->key << " ";
        temp = temp->next;        
    }
    std::cout << std::endl;
    delete temp;
}

void add_begin(datatype item) {
    Node *temp = new Node;
    temp->key = item;
    temp->next = first;
    temp->previous = NULL;
    if(last==NULL) {
        last = temp;
    } else {
        first->previous = temp;
    }
    first = temp;
}

void add_end(datatype item) {
    Node *temp = new Node;
    temp->key = item;
    temp->next = NULL;
    temp->previous = last;
    if(last==NULL) {
        first = temp;
    } else {
        last->next = temp;
    }
    last = temp;
}

void add_mid(datatype find, datatype item) {
    Node *pkey = search(find);
    if (pkey==NULL) {
        std::cout << "Error: item is not found" << std::endl;
        return;
    } else if (pkey==last) {
        add_end(item);
        return;
    }
    Node *temp = new Node;
    temp->key = item;
    temp->next = pkey->next;
    temp->previous = pkey;
    pkey->next = temp;
    (temp->next)->previous = temp;
}

void del_begin() {
    if (first == NULL) {
        std::cout << "Error: Queue is empty" << std::endl;
        return;
    }
    Node *temp = first;
    first = temp->next;
    first->previous = NULL;
    if (first==NULL) {
        last = NULL;
    } else {
        first->previous = NULL;
    }
    delete temp;
}

void del_end() {
    if (last == NULL) {
        std::cout << "Error: Queue is empty" << std::endl;
        return;
    }
    Node *temp = first;
    last = temp->previous;
    if (first==NULL) {
        first = NULL;
    } else {
        last->next = NULL;
    }
    delete temp;
}

void del_mid(datatype find) {
    Node *pkey = search(find);
    if (pkey==NULL) {
        std::cout << "Error: item is not found" << std::endl;
        return;
    } if (pkey==first) {
        del_begin();
        return;
    } else if (pkey==last) {
        del_end();
        return;
    }
    (pkey->previous)->next = pkey->next;
    (pkey->next)->previous = pkey->previous;
    delete pkey;
}

void showqueue() {
    Node *temp = new Node;
    std::cout << "Queue: ";
    temp = first;
    while (temp != NULL) {
        std::cout << temp->key << " ";
        temp = temp->next;        
    }
    std::cout << std::endl;
    delete temp;
}

void clear() {
    first = NULL;
    last = NULL;
}

Node* search(datatype item) {
    Node *temp = first;
    while (temp != NULL) {
        if (temp->key == item) {
            return temp;
        }
        temp = temp->next;
    }
}



