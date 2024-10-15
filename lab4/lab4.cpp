#include <iostream>
#include "List.h"

using namespace std;

void lab41() {
    pushstack(1); pushstack(2); pushstack(3); showstack();
    popstack(); showstack();
}

void lab42() {
    clear();
    add_begin(1); add_begin(2); add_begin(3); showqueue();
    del_begin(); showqueue();
}

void lab43() {
    clear();
    del_begin();
    add_end(1); add_begin(2); add_begin(3); showqueue();
    del_begin(); showqueue();
    cout << search(2) << endl;
    add_mid(2, 3); showqueue(); 
    del_mid(2); showqueue();
}

int main () {
    lab41();
    lab42();
    lab43();
    return 0;
}