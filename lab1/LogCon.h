#include <iostream>
#include <windows.h>
#include <functional>

using namespace std;

bool Not(bool a);
bool And(bool a, bool b);
bool Or(bool a, bool b);
bool If(bool a, bool b);
bool Xnor(bool a, bool b);
bool Xor(bool a, bool b);
void solve_variant(wstring* header, int sizeofheader, function<bool(bool a, bool b, bool c)> funcs[], string var_num);
void variant5();
void variant8();
void variant10();
void additional_variant();
void logic_operators_variant();


