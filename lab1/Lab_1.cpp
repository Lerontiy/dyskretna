#include <iostream>
#include <windows.h>
#include <functional>
#include "LogCon.h"

using namespace std;

void solve_variant(string header[], int sizeofheader, int spaces[], function<bool(bool a, bool b, bool c)> funcs[], int var_num);
void variant5();
void variant8();
void variant10();
int main();

void variant5() {
    auto one = [](bool a, bool b, bool c) {return a;};
    auto two = [](bool a, bool b, bool c) {return b;};
    auto three = [](bool a, bool b, bool c) {return c;}; 
    auto four = [](bool a, bool b, bool c) {return And(a, b);};
    auto five = [](bool a, bool b, bool c) {return Or(And(a, b), c);};
    auto six = [](bool a, bool b, bool c) {return Not(a);}; 
    auto seven = [](bool a, bool b, bool c) {return And(c, Not(a));};
    auto eight = [](bool a, bool b, bool c) {return Xnor(Or(And(a, b), c), And(c, Not(a)));};
    function<bool(bool a, bool b, bool c)> funcs[] = {one, two, three, four, five, six, seven, eight};
    
    string header[] = {"a", "b", "c", "a∧b", "(a∧b)∨c", "¬a", "c∧¬a", "((a∧b)∨c)~(c∧¬a)"};
    
    int spaces[] = {1, 1, 1, 3, 7, 2, 4, 16};

    int var_num = 5;

    int sizeofheader = sizeof(header)/24;

    solve_variant(header, sizeofheader, spaces, funcs, var_num);
}

void variant8() {
    auto one = [](bool a, bool b, bool c) {return a;};
    auto two = [](bool a, bool b, bool c) {return b;};
    auto three = [](bool a, bool b, bool c) {return c;}; 
    auto four = [](bool a, bool b, bool c) {return Not(a);};
    auto five = [](bool a, bool b, bool c) {return Or(c, Not(a));};
    auto six = [](bool a, bool b, bool c) {return Or(a, Or(c, Not(a)));}; 
    auto seven = [](bool a, bool b, bool c) {return Not(b);};
    auto eight = [](bool a, bool b, bool c) {return And(Not(b), a);};
    auto nine = [](bool a, bool b, bool c) {return Or(Not(b), c);};
    auto ten = [](bool a, bool b, bool c) {return Xor(And(Not(b), a), Or(Not(b), c));};
    auto eleven = [](bool a, bool b, bool c) {return Xnor(Or(a, Or(c, Not(a))), Xor(And(Not(b), a), Or(Not(b), c)));};
    function<bool(bool a, bool b, bool c)> funcs[] = {one, two, three, four, five, six, seven, eight, nine, ten, eleven};
    
    string header[] = {"a", "b", "c", "¬a", "c∨¬a", "a∨(c∨¬a)", "¬b", "¬b∧a", "¬b∨c", "¬b∧a⊕¬b∨c", "(a∨(c∨¬a))~((¬b∧a)⊕(¬b∨c))"};
    
    int spaces[] = {1, 1, 1, 2, 4, 8, 2, 4, 4, 9, 26};

    int var_num = 8;

    int sizeofheader = sizeof(header)/24;

    solve_variant(header, sizeofheader, spaces, funcs, var_num);
}

void variant10() {
    auto one = [](bool a, bool b, bool c) {return a;};
    auto two = [](bool a, bool b, bool c) {return b;};
    auto three = [](bool a, bool b, bool c) {return c;}; 
    auto four = [](bool a, bool b, bool c) {return Not(c);};
    auto five = [](bool a, bool b, bool c) {return And(b, c);};
    auto six = [](bool a, bool b, bool c) {return Or(a, c);}; 
    auto seven = [](bool a, bool b, bool c) {return If(And(b, c), Or(a, c));};
    auto eight = [](bool a, bool b, bool c) {return And(b, Not(c));};
    auto nine = [](bool a, bool b, bool c) {return And(c, a);};
    auto ten = [](bool a, bool b, bool c) {return If(And(b, Not(c)),  And(c, a));};
    auto eleven = [](bool a, bool b, bool c) {return Xnor(If(And(b, c), Or(a, c)), If(And(b, Not(c)),  And(c, a)));};
    function<bool(bool a, bool b, bool c)> funcs[] = {one, two, three, four, five, six, seven, eight, nine, ten, eleven};
    
    string header[] = {"a", "b", "c", "¬c", "b∧c", "a∨c", "(b∧c)→(a∨c)", "b∧¬c", "c∧a", "(b∧¬c)→(c∧a)", "((b∧c)→(a∨c))~((b∧¬c)→(c∧a))"};

    int spaces[] = {1, 1, 1, 2, 3, 3, 11, 4, 3, 12, 28};

    int var_num = 10;

    int sizeofheader = sizeof(header)/24;

    solve_variant(header, sizeofheader, spaces, funcs, var_num);
}
    
void solve_variant(string header[], int sizeofheader, int spaces[], function<bool(bool a, bool b, bool c)> funcs[], int var_num) {
    bool elements[] = {true, false};

    cout << " " << "Варіант " << var_num << "\n";

    cout << " | ";
    for (int i=0; i<sizeofheader; i++) {
        cout<< header[i] << " | ";
    }
    cout << "\n";
    
    //sort(elements.begin(), elements.end());
    for (bool c : elements) {
        for (bool b : elements) {
            for (bool a : elements) {
                cout << " | ";
                for (int iv=0; iv<sizeofheader; iv++) {
                    bool can_skip = true;
                    for (int v=0; v<spaces[iv]/2; v++) {
                        if (can_skip && spaces[iv]%2==0) {
                            can_skip = false;
                            continue;
                        }
                        cout << " ";
                    }
                    cout << (funcs[iv](a, b, c) ? "1" : "0");
                    for (int v=0; v<spaces[iv]/2; v++) { cout << " ";}
                    cout << " | ";
                }
                cout << endl;
            }
        }
    }
    cout << endl;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    variant5();
    variant8();
    variant10();
    
    return 0;
}
