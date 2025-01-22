#include <bits/stdc++.h>
using namespace std;

vector<string> tokens;
int cur = 0;

int eval() {
    string op = tokens[cur++]; 

    if (op == "f") {
        int x = eval();
        return 2 * x - 3;
    } 
    else if (op == "g") {
        int x = eval();
        int y = eval();
        return 2 * x + y - 7;
    }
    else if (op == "h") {
        int x = eval();
        int y = eval();
        int z = eval();
        return 3 * x - 2 * y + z;
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
