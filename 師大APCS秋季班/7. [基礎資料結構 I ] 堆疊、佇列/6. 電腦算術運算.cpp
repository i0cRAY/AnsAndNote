#include <bits/stdc++.h>
using namespace std;

int eval(string &expr, int &i) {
    if (i >= expr.size() || expr[i] != '(') return -1;
    i++;

    int n1 = 0;
    if (isdigit(expr[i])) {
        while (isdigit(expr[i])) {
            n1 = n1 * 10 + (expr[i] - '0');
            i++;
        }
    } else if (expr[i] == '(') {
        n1 = eval(expr, i);
        if (n1 == -1) return -1;
    } else {
        return -1;
    }

    if (i >= expr.size() || expr[i] != ',') return -1;
    i++;

    int n2 = 0;
    if (isdigit(expr[i])) {
        while (isdigit(expr[i])) {
            n2 = n2 * 10 + (expr[i] - '0');
            i++;
        }
    } else if (expr[i] == '(') {
        n2 = eval(expr, i);
        if (n2 == -1) return -1;
    } else {
        return -1;
    }

    if (i >= expr.size() || expr[i] != ',') return -1;
    i++;

    if (i >= expr.size() || (expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/')) return -1;
    char op = expr[i++];
    
    if (i >= expr.size() || expr[i] != ')') return -1;
    i++;

    if (op == '+') return n1 + n2;
    if (op == '-') return n1 - n2;
    if (op == '*') return n1 * n2;
    if (op == '/') return n2 == 0 ? -1 : n1 / n2;
    return -1;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        string expr;
        getline(cin, expr);

        int i = 0;
        int res = eval(expr, i);

        if (res == -1 || i != expr.size()) {
            cout << -1 << endl;
        } else {
            cout << res << endl;
        }
    }

    return 0;
}
