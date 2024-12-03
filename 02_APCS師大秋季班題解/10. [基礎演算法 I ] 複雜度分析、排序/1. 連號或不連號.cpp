#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int j = a[0];  bool ans = true;
	for (int i = 0; i < n; i++, j++) {
		if (a[i] != j) {
			ans = false;
			break;
		}
	}

	cout << a[0] << ' ' << a[n - 1] << ' ';
	if (ans) {
		cout << "yes";
	}
	else {
		cout << "no";
	}
}
