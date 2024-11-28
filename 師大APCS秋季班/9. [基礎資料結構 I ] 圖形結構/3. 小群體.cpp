#include <bits/stdc++.h>
using namespace std;

void dfs(int person, vector<int>& friends, vector<bool>& vis) {
    int cur = person;
    while (!vis[cur]) {
        vis[cur] = true;
        cur = friends[cur];
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> friends(N);
    for (int i = 0; i < N; ++i) {
        cin >> friends[i];
    }

    vector<bool> vis(N, false);
    int groups = 0;

    for (int i = 0; i < N; ++i) {
        if (!vis[i]) {
            groups++;
            dfs(i, friends, vis);
        }
    }

    cout << groups << endl;
    return 0;
}
