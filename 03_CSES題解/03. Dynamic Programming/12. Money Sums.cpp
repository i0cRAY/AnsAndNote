#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, sum = 0;
    cin >> n;
 
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
 
    vector<bool> dp(sum + 1, false);
    dp[0] = true; 
 
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= a[i]; j--) {
            if (dp[j - a[i]]) {
                dp[j] = true;
            }
        }
    }
 
    int cnt = 0;
    vector<int> ans;
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) {
            cnt++;
            ans.push_back(i);
        }
    }
 
    cout << cnt << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
 
    return 0;
}
