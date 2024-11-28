#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, time = 0, ans = 0;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second; 
    }

    for (int i = 0; i < n; i++) {
        if (time >= v[i].first) {
            time += v[i].second; 
        } else {
            time = v[i].first + v[i].second; 
        }

        int wait = 0;
        for (int j = i + 1; j < n && v[j].first <= time; j++) {
            wait++; 
        }

        ans = max(ans, wait);
    }

    cout << ans << '\n'; 
    return 0;
}
