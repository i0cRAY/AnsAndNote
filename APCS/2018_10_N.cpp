#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, s, n;
    cin >> m >> s >> n;

     m -= s;

     int total = 0;

     vector<int> a(n + 1);
     for (int i = 1; i <= n; i++)
     {
          cin >> a[i];
          total += a[i];
     }
         

     // 定義 dp[i][j] 為前 i 項空間不超過 j 的最多櫃子數
     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

     for (int i = 1; i <= n; i++)
     {
         for (int j = 1; j <= m; j++)
         {
             // 放不下 a[i]
             if (j < a[i])
                 dp[i][j] = dp[i - 1][j];
             else
                 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + a[i]);
         }
     }

     cout << total - dp[n][m];

    return 0;
}
