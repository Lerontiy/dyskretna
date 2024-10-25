#include "Converter.h"
#include "../lab4/List.h"
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>  // Для reverse

// Функція визначення пріоритету оператора
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Конвертація з інфіксної у постфіксну форму
std::string InfixToPostfix(std::string infix) {
    std::stack<char> s;
    std::string postfix;

    for (std::size_t i = 0; i < infix.size(); ++i) {
        if (isdigit(infix[i])) {
            while (i < infix.size() && isdigit(infix[i])) {
                postfix += infix[i++];
            }
            postfix += ' ';
            --i;
        } else if (infix[i] == '(') {
            s.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && precedence(s.top()) >= precedence(infix[i])) {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }
    return postfix;
}

// Конвертація з інфіксної у префіксну форму
std::string InfixToPrefix(std::string infix) {
    std::string reversedInfix = infix;
    std::reverse(reversedInfix.begin(), reversedInfix.end());

    // Міняємо дужки
    for (char& ch : reversedInfix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    std::string postfix = InfixToPostfix(reversedInfix);
    std::string prefix = postfix;
    std::reverse(prefix.begin(), prefix.end());
    return prefix;
}

// Конвертація з постфіксної у інфіксну форму
std::string PostfixToInfix(std::string postfix) {
    std::stack<std::string> s;
    std::string token;

    for (std::size_t i = 0; i < postfix.size(); ++i) {
        if (isdigit(postfix[i])) {
            token.clear();
            while (i < postfix.size() && isdigit(postfix[i])) {
                token += postfix[i++];
            }
            s.push(token);
        } else if (postfix[i] != ' ') {
            std::string op2 = s.top(); s.pop();
            std::string op1 = s.top(); s.pop();
            std::string exp = "(" + op1 + " " + postfix[i] + " " + op2 + ")";
            s.push(exp);
        }
    }
    return s.top();
}

// Конвертація з префіксної у інфіксну форму
std::string PrefixToInfix(std::string prefix) {
    std::stack<std::string> s;

    for (int i = prefix.size() - 1; i >= 0; --i) {
        if (isdigit(prefix[i])) {
            std::string token;
            while (i >= 0 && isdigit(prefix[i])) {
                token = prefix[i--] + token;
            }
            s.push(token);
        } else if (prefix[i] != ' ') {
            std::string op1 = s.top(); s.pop();
            std::string op2 = s.top(); s.pop();
            std::string exp = "(" + op1 + " " + prefix[i] + " " + op2 + ")";
            s.push(exp);
        }
    }
    return s.top();
}

/*

string InfixToPrefix1(string s) {
    string ret_s = "";
    
    for (int ii = s.length()-1; ii>=0; ii--) {
        char i = s[ii];
        if (isdigit(i) || i=='a' || i=='b' || i=='c' || i=='x' || i=='d' || i==')') {
            if (i==')') {
                //ret_s+= i;
            } else {
                ret_s+= i;
            }
        } else if (i=='+' || i=='-' || i=='*' || i=='/' || i=='^') {
            pushstack(i);
        } else {
            //ret_s += i;
            //ret_s += '(';
            for (int i=0; i<5; i++) {add_to_string(ret_s);}
        } 
    }
    for (int i=0; i<5; i++) {add_to_string(ret_s);}

    for (int i=0; i<ret_s.length()/2; i++){
        char g = ret_s[i];
        ret_s[i] = ret_s[(ret_s.length()-1-i)];
        ret_s[(ret_s.length()-1-i)] = g;
    }

    return ret_s;
}

string PostfixToInfix1(string s){
    string ret_s = " ";

    for (char i : s) {
        if (isdigit(i) || i=='a' || i=='b' || i=='c' || i=='x' || i=='d' || i==')') {
            pushstack(i);
            
        } else if (i=='+' || i=='-' || i=='*' || i=='/' || i=='^') {
            string l[2];
            for (int ii=0; ii<2; ii++) {
                add_to_string(l[ii]);
                if (l[ii]=="(") {}
            }
            pushstack(')');
            //pushstack(l[0]);
            pushstack(i);
            //pushstack(l[1]);
            pushstack('(');            
        }
        
    }

    return ret_s;
}

*/