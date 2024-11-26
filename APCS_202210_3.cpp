#include <bits/stdc++.h>
using namespace std;

long long sum = 0;

void dfs(int p) {
    int c;
    cin >> c;

    if (c == 0) {
        return;
    }
    else {
        if (p != 0) {
            sum += abs(p - c);
        }
        if (c % 2 == 0) {
            dfs(c);
            dfs(c);
        }
        else {
            dfs(c);
            dfs(c);
            dfs(c);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    dfs(0);
    cout << sum;
    return 0;    
}