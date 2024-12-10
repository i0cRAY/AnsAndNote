#include <bits/stdc++.h>
using namespace std;

map<int, int> ans;
vector<int> adj[51005], gates[51005];

struct s {
	int Id, Signal, Delate;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int p, q, r, m;
	cin >> p >> q >> r >> m;

	queue<s> Q;
	for (int i = 1; i <= p; i++) {
		int input;
		cin >> input;
		Q.push({ i, input, 0 });
	}

	vector<int> logic(p + q + 1);
	for (int i = p + 1; i <= p + q; i++) {
		cin >> logic[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	int time = 0;
	while (!Q.empty()) {
		int u = Q.front().Id;
		int signal = Q.front().Signal;
		int delate = Q.front().Delate;
		Q.pop();

		for (auto v : adj[u]) {
			if (p + q < v) {
				ans[v] = signal;
				time = max(time, delate);
			}
			else {
				if (logic[v] == 1) {
					gates[v].push_back(signal);
					if (gates[v].size() == 2) {
						if (gates[v][0] == 1 && gates[v][1] == 1) {
							Q.push({ v, 1, delate + 1 });
						}
						else {
							Q.push({ v, 0, delate + 1 });
						}
					}
				}
				else if (logic[v] == 2) {
					gates[v].push_back(signal);
					if (gates[v].size() == 2) {
						if (gates[v][0] == 1 || gates[v][1] == 1) {
							Q.push({ v, 1, delate + 1 });
						}
						else {
							Q.push({ v, 0, delate + 1 });
						}
					}
				}
				else if (logic[v] == 3) {
					gates[v].push_back(signal);
					if (gates[v].size() == 2) {
						if (gates[v][0] != gates[v][1]) {
							Q.push({ v, 1, delate + 1 });
						}
						else {
							Q.push({ v, 0, delate + 1 });
						}
					}
				}
				else {
					gates[v].push_back(signal);
					if (gates[v][0] == 0) {
						Q.push({ v, 1, delate + 1 });
					}
					else {
						Q.push({ v, 0, delate + 1 });
					}
				}
			}
		}
	}

	cout << time << '\n';
	for (auto mp : ans) {
		cout << mp.second << ' ';
	}

	return 0;
}
