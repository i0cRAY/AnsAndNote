#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1); 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -10005));
    dp[0][0] = 0; 
    int mx = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            // 1. 不使用金牌，直接拿當天收益
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i]);

            // 2. 使用金牌，跳過當天
            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            }

            // 3. 不投資
            dp[i][j] = max(dp[i][j], 0);
            
            mx = max(mx, dp[i][j]);
        }
    }

    cout << mx; 
    return 0;
}