#include <iostream>
#include "Converter.h"

using namespace std;

int main () {
    //string infix = "(a+b)*(c+d)^x";
    string infix = "(144+25)*(c+d)^x";
    string postfix = InfixToPostfix(infix);
    string prefix = InfixToPrefix(infix);

    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << " " << (postfix=="ab+cd+x^*") << endl;
    cout << "Prefix: " << prefix << " " << (prefix=="*+ab^+cdx") << endl;
    cout << "Infix: " << PostfixToInfix(postfix) << endl;
    cout << "Infix: " << PrefixToInfix(prefix) << endl;

    return 0;
}