#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<int> p(n); vector<int> q(m);
	for (int i = 0; i < n; i++) { cin >> p[i]; }
	for (int i = 0; i < m; i++) { cin >> q[i]; }
	int point = 0; int Q = 0; int P = 0;
	while (true) {
		if (P == p.size()) { P = 0; }
		point += p[P];
		if (point >= q[Q]) {
			//cout << P << " " << point << endl;
			point = 0;
			Q++; 
		}
		if (Q == q.size()) { break; }
		P++;
	}
	if (P == p.size() - 1) { cout << 0; }
	else { cout << P + 1; }
}
