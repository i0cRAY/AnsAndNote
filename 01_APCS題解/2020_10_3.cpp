#include <bits/stdc++.h>
using namespace std;
int a[55][10005], dp[55][10005][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j][0] = max({dp[i][j - 1][0], dp[i - 1][j][0], dp[i - 1][j][1]}) + a[i][j];
        }
        for (int j = n; j >= 1; j--) {
            dp[i][j][1] = max({dp[i][j + 1][1], dp[i - 1][j][0], dp[i - 1][j][1]}) + a[i][j];
        }
    }

    int ans = INT_MIN;
    for (int j = 1; j <= n; j++) {
        ans = max({ans, dp[m][j][0], dp[m][j][1]});
    }
    cout << ans;
    return 0;
}
