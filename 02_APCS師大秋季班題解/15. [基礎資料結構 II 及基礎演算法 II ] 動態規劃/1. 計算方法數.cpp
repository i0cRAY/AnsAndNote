v#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	vector<int> coins = { 1, 5, 10, 25, 50 };

	vector<long long> dp(30005, 0);
	dp[0] = 1;
	for (int c : coins) {
		for (int i = c; i <= 30000; i++) {
			dp[i] += dp[i - c];
		}
	}

	while (cin >> n) {
		if (dp[n] == 1) {
			cout << "There is only 1 way to produce " << n << " cents change." << '\n';
		}
		else {
			cout << "There are " << dp[n] << " ways to produce " << n << " cents change." << '\n';
		}
	}
	return 0;
}
