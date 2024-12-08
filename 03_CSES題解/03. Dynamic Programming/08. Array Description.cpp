#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    
    if (a[1] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[1][i] = 1;
        }
    }
    else {
        dp[1][a[1]] = 1;
    }

    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j > 1) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                }
                if (j < m) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
                }
            }
        }
        else {
            dp[i][a[i]] = dp[i - 1][a[i]];
            if (a[i] > 1) {
                dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] - 1]) % mod;
            }
            if (a[i] < m) {
                dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] + 1]) % mod;
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans = (ans + dp[n][j]) % mod;
    }

    cout << ans;
    return 0;
}
