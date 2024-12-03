#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
 
    int n, x;
    cin >> n >> x;
    
    int p[1005];
    int b[1005];
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (j >= p[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p[i]] + b[i]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    cout << dp[n][x];
    return 0;
}
