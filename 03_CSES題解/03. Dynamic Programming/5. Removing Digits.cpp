#include <bits/stdc++.h>
using namespace std;

int dp[1000005];

int f(int n) {
    if (dp[n] != INT_MAX) {
        return dp[n];
    }

    string s = to_string(n);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            continue;
        }
        dp[n] = min(dp[n], f(n - (s[i] - '0')) + 1);
    }
    return dp[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < 10; i++) {
        dp[i] = 1;
    }
    for (int i = 10; i <= n; i++) {
        dp[i] = INT_MAX;
    }

    cout << f(n);

    return 0;
}
