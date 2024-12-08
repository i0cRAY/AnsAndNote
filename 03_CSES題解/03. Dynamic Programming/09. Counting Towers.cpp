#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    // 0 為下面分開，1 為不分開
    vector<vector<int>> dp(1000005, vector<int>(2));
    dp[1][0] = 1, dp[1][1] = 1;

    for (int i = 2; i < 1000005; i++) {
        dp[i][0] = (4 * dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][1] = (2 * dp[i - 1][1] + dp[i - 1][0]) % mod;
    }

    while (t--) {
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % mod << '\n';
    }

    return 0;
}
