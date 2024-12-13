#include <bits/stdc++.h>
using namespace std;

int n, l;

bool cmp(pair<int, int> p, pair<int, int> q) {
	return p.second < q.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l;
	
	set<int> p;
	p.insert(0);
	p.insert(l);

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	sort(a.begin(), a.end(), cmp);

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int cut = a[i].first;

		auto it = p.lower_bound(cut);
		int r = *it;
		it--;
		int l = *it;
		p.insert(cut);
		// cout << l << ' ' << r << '\n';
		ans += (r - l);
	}

	cout << ans;
	return 0;
}
