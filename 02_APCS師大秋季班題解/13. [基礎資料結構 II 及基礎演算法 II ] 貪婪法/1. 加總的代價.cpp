#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n && n != 0) {

		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			pq.push(a);
		}

		int ans = 0;
		while (pq.size() > 1) {
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();

			int c = a + b;
			ans += c;
			pq.push(c);
		}

		cout << ans << '\n';
	}

	return 0;
}
