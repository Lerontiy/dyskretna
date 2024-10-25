#include <iostream>
#include <stack>
#include <string>
#include <algorithm>  

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string InfixToPostfix(const string& infix) {
    stack<char> s;
    string postfix;

    for (size_t i = 0; i < infix.size(); ++i) {
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

string InfixToPrefix(const string& infix) {
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end());

    for (char& ch : reversedInfix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    string postfix = InfixToPostfix(reversedInfix);
    string prefix = postfix;
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

string PostfixToInfix(const string& postfix) {
    stack<string> s;
    string token;

    for (size_t i = 0; i < postfix.size(); ++i) {
        if (isdigit(postfix[i])) {
            token.clear();
            while (i < postfix.size() && isdigit(postfix[i])) {
                token += postfix[i++];
            }
            s.push(token);
        } else if (postfix[i] != ' ') {
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            string exp = "(" + op1 + " " + postfix[i] + " " + op2 + ")";
            s.push(exp);
        }
    }
    return s.top();
}

string PrefixToInfix(const string& prefix) {
    stack<string> s;

    for (int i = prefix.size() - 1; i >= 0; --i) {
        if (isdigit(prefix[i])) {
            string token;
            while (i >= 0 && isdigit(prefix[i])) {
                token = prefix[i--] + token;
            }
            s.push(token);
        } else if (prefix[i] != ' ') {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string exp = "(" + op1 + " " + prefix[i] + " " + op2 + ")";
            s.push(exp);
        }
    }
    return s.top();
}

int main() {
    string infix = "(144+25)";
    //string poag;
    //cout << "Wwedit infixnu formu: ";
    //cin >> infix;

    cout << "Infix: " << infix << endl;

    string postfix = InfixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    string prefix = InfixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;

    string infixFromPostfix = PostfixToInfix(postfix);
    cout << "Infix from Postfix: " << infixFromPostfix << endl;

    string infixFromPrefix = PrefixToInfix(prefix);
    cout << "Infix from Prefix: " << infixFromPrefix << endl;

    return 0;
}
