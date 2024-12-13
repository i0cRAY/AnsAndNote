#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n1, n2, t = 0;
	while (cin >> n1 >> n2 && (n1 != 0 && n2 != 0)) {
		t++;
		vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

		vector<int> a1(n1 + 1);
		vector<int> a2(n2 + 1);

		for (int i = 1; i <= n1; i++) {
			cin >> a1[i];
		}
		for (int i = 1; i <= n2; i++) {
			cin >> a2[i];
		}

		for (int i = 1; i <= n1; i++) {
			for (int j = 1; j <= n2; j++) {
				if (a1[i] == a2[j]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}

		cout << "Twin Towers #" << t << '\n';
		cout << "Number of Tiles : " << dp[n1][n2] << '\n' << '\n';
	}

	return 0;
}
