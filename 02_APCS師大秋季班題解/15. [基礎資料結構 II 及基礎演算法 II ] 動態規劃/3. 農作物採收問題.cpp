#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[105][105], n;

int total(vector<int> s) {
	int mx = s[0], curr = s[0];
	for (int i = 1; i < n; i++) {
		curr = max(s[i], curr + s[i]);
		mx = max(mx, curr);
	}
	return mx;
}

int f() {
	int mx = INT_MIN;
	vector<int> s(n);
	for (int top = 0; top < n; top++) {
		fill(s.begin(), s.end(), 0); 
		for (int bottom = top; bottom < n; bottom++) {
			for (int i = 0; i < n; i++) {
				s[i] += a[bottom][i];
			}
			mx = max(mx, total(s));
		}
	}
	return mx;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	cout << f();

	return 0;
}
