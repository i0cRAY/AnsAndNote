#include <bits/stdc++.h>
using namespace std;

bool canReach(int N, int M, vector<pair<int, int>>& roads, int A, int B) {
    vector<vector<int>> adj(N + 1);

    for (auto& r : roads) {
        adj[r.first].push_back(r.second);
    }

    vector<bool> vis(N + 1, false);
    stack<int> st;
    st.push(A);

    while (!st.empty()) {
        int cur = st.top();
        st.pop();

        if (cur == B) return true;

        if (!vis[cur]) {
            vis[cur] = true;
            for (int next : adj[cur]) {
                if (!vis[next]) st.push(next);
            }
        }
    }
    return false;
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        vector<pair<int, int>> roads(M);
        for (int i = 0; i < M; ++i) {
            int x, y;
            cin >> x >> y;
            roads[i] = {x, y};
        }
        int A, B;
        cin >> A >> B;

        cout << (canReach(N, M, roads, A, B) ? "Yes" : "No") << '\n';
    }
    return 0;
}
