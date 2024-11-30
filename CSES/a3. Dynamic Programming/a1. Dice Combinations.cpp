#include <bits/stdc++.h>
using namespace std;

/*
dp[i] 為數字 i 的組合方式
如果最一顆骰子為 1，那他組合數便包含 dp[i - 1] (i = (i - 1) + 1)
故dp[i] = dp[i - n]的加總，其中 n = 1~6
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % (int)(1e9 + 7);
            }
        }
    }
    
    cout << dp[n];
    return 0;
}
