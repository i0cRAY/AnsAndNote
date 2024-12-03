#include <bits/stdc++.h>
using namespace std;

int n, vk, q;
bool visited[5005];
int d[5005]; // d[i] 為 vk 到 i 的相關性
vector<pair<int, int>> adj[5005];

void dfs(int u, int w) {
	visited[u] = true;
	for (auto e : adj[u]) {
		int v = e.first;
		int r = e.second;

		if (!visited[v]) {
			dfs(v, min(w, r));
		}
	}

	d[u] = w;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> vk >> q;
	for (int t = 0; t < n - 1; t++) {
		int i, j, w;
		cin >> i >> j >> w;

		adj[i].push_back({ j, w });
		adj[j].push_back({ i, w });
	}

	dfs(vk, INT_MAX);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] >= q) {
			ans++;
		}
	}

	cout << ans - 1;
}
