#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	sort(a.begin(), a.end());

	vector<int> lis;
	for (int i = 0; i < n; i++)
	{
		auto it = upper_bound(lis.begin(), lis.end(), a[i].second);
		if (it == lis.end())
			lis.push_back(a[i].second);
		else
			*it = a[i].second;
	}
	
	cout << lis.size();
	return 0;
}
