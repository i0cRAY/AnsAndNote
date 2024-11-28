#include <bits/stdc++.h>
using namespace std;

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string toPostfix(const string &infix) {
    stack<char> ops;
    string post = "";

    for (char c : infix) {
        if (isalpha(c)) {
            post += c;
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                post += ops.top();
                ops.pop();
            }
            if (!ops.empty()) ops.pop();
        } else {
            while (!ops.empty() && prec(ops.top()) >= prec(c)) {
                post += ops.top();
                ops.pop();
            }
            ops.push(c);
        }
    }

    while (!ops.empty()) {
        post += ops.top();
        ops.pop();
    }

    return post;
}

int main() {
    string infix;
    cin >> infix;

    cout << toPostfix(infix) << endl;

    return 0;
}
