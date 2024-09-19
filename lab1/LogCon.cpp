#include "LogCon.h"
#include <functional>
#include <locale>
#include <codecvt>

bool Not(bool a){ // return !a
    if (a){
        return false;
    }
    return true;
}

bool And(bool a, bool b){ // return a && b;
    if (a){
        if (b){
            return true;
        }
    }
    return false;
}

bool Or(bool a, bool b){ // return a || b;
    if (a){
        return true;
    }else if (b){
        return true;
    } 
    return false;
}

bool If(bool a, bool b){ // if (a) {return b;} else {return !b;}
    if (a){
        return b;
    }
    return Not(b);
}

bool Xnor(bool a, bool b){ // return a==b;
    if (a) {
        if (b) {
            return true;
        }
        return false;
    } else if (b) {
        return false;
    }
    return true;
}
bool Xor(bool a, bool b){ // return a!=b;
    if (a) {
        if (b) {
            return false;
        }
        return true;
    } else if (b) {
        return true;
    }
    return false;
}

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
    
    wstring header[] = {L"a", L"b", L"c", L"a∧b", L"(a∧b)∨c", L"¬a", L"c∧¬a", L"((a∧b)∨c)~(c∧¬a)"};

    string var_num = "5";

    int sizeofheader = sizeof(header) / sizeof(header[0]);

    solve_variant(header, sizeofheader, funcs, var_num);
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
    
    wstring header[] = {L"a", L"b", L"c", L"¬a", L"c∨¬a", L"a∨(c∨¬a)", L"¬b", L"¬b∧a", L"¬b∨c", L"¬b∧a⊕¬b∨c", L"(a∨(c∨¬a))~((¬b∧a)⊕(¬b∨c))"};

    string var_num = "8";

    int sizeofheader = sizeof(header) / sizeof(header[0]);

    solve_variant(header, sizeofheader, funcs, var_num);
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
    
    wstring header[] = {L"a", L"b", L"c", L"¬c", L"b∧c", L"a∨c", L"(b∧c)→(a∨c)", L"b∧¬c", L"c∧a", L"(b∧¬c)→(c∧a)", L"((b∧c)→(a∨c))~((b∧¬c)→(c∧a))"};

    string var_num = "10";

    int sizeofheader = sizeof(header) / sizeof(header[0]);

    solve_variant(header, sizeofheader, funcs, var_num);
}

void additional_variant() { // (a→b)v(⌐c→(⌐a⊕⌐b))
    auto one = [](bool a, bool b, bool c) {return a;};
    auto two = [](bool a, bool b, bool c) {return b;};
    auto three = [](bool a, bool b, bool c) {return c;}; 
    auto four = [](bool a, bool b, bool c) {return If(a, b);};
    auto five = [](bool a, bool b, bool c) {return Not(a);};
    auto six = [](bool a, bool b, bool c) {return Not(b);}; 
    auto seven = [](bool a, bool b, bool c) {return Not(c);};
    auto eight = [](bool a, bool b, bool c) {return Xor(Not(a), Not(b));};
    auto nine = [](bool a, bool b, bool c) {return If(Not(c), Xor(Not(a), Not(b)));};
    auto ten = [](bool a, bool b, bool c) {return Or(If(a, b), If(Not(c), Xor(Not(a), Not(b))));};
    function<bool(bool a, bool b, bool c)> funcs[] = {one, two, three, four, five, six, seven, eight, nine, ten};
    
    wstring header[] = {L"a", L"b", L"c", L"a→b", L"⌐a", L"⌐b", L"⌐c", L"⌐a⊕⌐b", L"⌐c→(⌐a⊕⌐b)", L"(a→b)v(⌐c→(⌐a⊕⌐b))"};

    string var_num = "Лаболаторний";

    int sizeofheader = sizeof(header) / sizeof(header[0]);

    solve_variant(header, sizeofheader, funcs, var_num);
}

void logic_operators_variant() { // (a→b)v(⌐c→(⌐a⊕⌐b))
    auto one = [](bool a, bool b, bool c) {return a;};
    auto two = [](bool a, bool b, bool c) {return b;};
    auto three = [](bool a, bool b, bool c) {return Not(a);}; 
    auto four = [](bool a, bool b, bool c) {return And(a, b);};
    auto five = [](bool a, bool b, bool c) {return Or(a, b);};
    auto six = [](bool a, bool b, bool c) {return If(a, b);}; 
    auto seven = [](bool a, bool b, bool c) {return Xnor(a, b);};
    auto eight = [](bool a, bool b, bool c) {return Xor(a, b);};
    function<bool(bool a, bool b, bool c)> funcs[] = {one, two, three, four, five, six, seven, eight};
    
    wstring header[] = {L"a", L"b", L"⌐a", L"a∧b", L"avb", L"a→b", L"a~b", L"a⊕b"};
    int sizeofheader = sizeof(header) / sizeof(header[0]);

    string var_num = "Логічні Операції";

    solve_variant(header, sizeofheader, funcs, var_num);
}
    
void solve_variant(wstring* header, int sizeofheader, function<bool(bool a, bool b, bool c)> funcs[], string var_num) {

    bool elements[] = {true, false};

    int spaces[sizeofheader];

    wstring_convert<codecvt_utf8<wchar_t>> converter;

    for (int i=0; i<sizeofheader; i++){
        spaces[i] = header[i].length();
    }

    cout << " " << "Варіант " << var_num << endl;

    cout << " | ";
    for (int i=0; i<sizeofheader; i++) {
        string utf8_string = converter.to_bytes(header[i]);
        cout << utf8_string << " | ";
    }
    cout << endl;
    
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

