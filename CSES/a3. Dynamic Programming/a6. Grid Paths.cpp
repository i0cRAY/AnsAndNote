#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    char a[1005][1005];
    int dp[1005][1005];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    a[0][0] == '*' ? dp[0][0] = 0 : dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i][0] != '*') {
            dp[i][0] = dp[i - 1][0];
        }
        if (a[0][i] != '*') {
            dp[0][i] = dp[0][i - 1];
        }
    }
    
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i][j] != '*') {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % (int)(1e9 + 7);
            }
        }
    }
 
    cout << dp[n - 1][n - 1];
    return 0;
}
