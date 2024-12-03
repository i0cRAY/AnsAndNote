#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, x;
    cin >> n >> x;
 
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
 
    vector<int> dp(x + 1, 1e6 + 1);
    dp[0] = 0;
 
    for (int i = 1; i <= x; i++) {
        for (int c = 0; c < n; c++) {
            if (i >= coins[c]) {
                dp[i] = min(dp[i], dp[i - coins[c]] + 1);
            }
        }
    }
 
    dp[x] == (1e6 + 1) ? cout << -1 : cout << dp[x];
    return 0;
}
