#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n % 4 == 1 || n % 4 == 2) {
        cout << 0;
        return 0;
    }

    int set_sum = n * (n + 1) / 4;
    vector<vector<int>> dp(n + 1, vector<int>(set_sum + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= set_sum; j++) {
            if (j < i) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - i]) % (int)(1e9 + 7);
            }
        }
    }
    
    cout << (1LL * dp[n][set_sum] * 500000004) % (int)(1e9 + 7);
    return 0;
}
