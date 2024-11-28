#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    while (cin >> n && n != 0) {
        int a0;
        while (cin >> a0 && a0 != 0) {
            queue<int> q;
            for (int i = 1; i <= n; i++) {
                q.push(i);
            }

            vector<int> a(n);
            a[0] = a0;
            for (int i = 1; i < n; i++) {
                cin >> a[i];
            }

            stack<int> s; int t = 0;
            while (!q.empty()) {
                int N = q.front();
                q.pop();
                // 能夠匹配
                if (N == a[t]) {
                    t++;
                    // 檢查棧是否能匹配
                    while (!s.empty() && s.top() == a[t]) {
                        s.pop();
                        t++;
                    }
                }
                // 無法匹配
                else {
                    // 丟到棧裡
                    s.push(N);
                }
            }

            if (s.empty()) {
                cout << "Yes" << '\n';
            }
            else {
                cout << "No" << '\n';
            }
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
