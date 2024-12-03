#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < m; i++) {
		pq.push(0);
	}

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		int t = pq.top();
		pq.pop();

		t += a[i];
		pq.push(t);
	}

	while (pq.size() > 1) {
		pq.pop();
	}
	cout << pq.top();

	return 0;
}
