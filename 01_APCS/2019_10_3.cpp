#include <bits/stdc++.h>
using namespace std;

struct st { int index, step; };

int ans = -1;
int n, p, l, r;
int s[1000005];
bool visit[1000005] = { false };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p >> l >> r;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    queue<st> q;
    q.push({ 0, 0 });
    visit[0] = true;

    while (!q.empty()) {
        st f = q.front();
        q.pop();

        if (f.index == p) {
            cout << f.step << endl;
            return 0;
        }

        // 往左走
        int le = f.index - l;
        if (le >= 0) {
            int le2 = s[le];
            if (le2 >= 0 && le2 < n && !visit[le2]) {
                visit[le2] = true;
                q.push({ le2, f.step + 1 });
            }
        }

        // 往右走
        int ri = f.index + r;
        if (ri < n) {
            int ri2 = s[ri];
            if (ri2 >= 0 && ri2 < n && !visit[ri2]) {
                visit[ri2] = true;
                q.push({ ri2, f.step + 1 });
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
