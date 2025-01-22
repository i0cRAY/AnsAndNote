#include <bits/stdc++.h>
using namespace std;

vector<string> tokens;
int cur = 0;

int eval() {
    string op = tokens[cur++]; 

    if (op == "f") {
        int x = eval();
        return 2 * x - 1;
    } 
    else if (op == "g") {
        int x = eval();
        int y = eval();
        return x + 2 * y - 3;
    } 
    else {
        return stoi(op);
    }
}

int main() {
    string line;
    getline(cin, line);

    istringstream iss(line);
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }

    cout << eval();
    return 0;
}