#include <bits/stdc++.h>
using namespace std;

int n, m, k, t, cnt = 0;
queue<int> have;
vector<int> open_box[100005], acquire[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k >> t;

    vector<int> need(n, k);
    vector<bool> used(m);

    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;
        have.push(a);
        used[a] = true;
    }
    for (int i = 0; i < n; i++) {
        int a;
        for (int j = 0; j < k; j++) {
            cin >> a;
            open_box[a].push_back(i);
        }
    }
    for (int i = 0; i < n; i++) {
        int a;
        for (int j = 0; j < k; j++) {
            cin >> a;
            acquire[i].push_back(a);
        }
    }

    while (!have.empty()) {
        int key = have.front();
        have.pop();

        for (auto b : open_box[key]) {
            need[b]--;

            // can open
            if (need[b] == 0) {
                cnt++;
                for (auto k : acquire[b]) {
                    if (!used[k]) {
                        have.push(k);
                        used[k] = true;
                    }
                }
            }
        }
    }

    cout << cnt;
    return 0;
}
