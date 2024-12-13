#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> w, a;
    int k;

    string line1, line2;
    getline(cin, line1); 
    getline(cin, line2); 
    cin >> k; 

    stringstream ss1(line1), ss2(line2);
    int t;
    while (ss1 >> t) w.push_back(t);
    while (ss2 >> t) a.push_back(t);

    int n = a.size();
    vector<int> dp(k + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + a[i]);
        }
    }

    cout << dp[k] << '\n';
    return 0;
}
