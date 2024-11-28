#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	char c;
	cin >> s >> c;

	c = toupper(c);

	vector<int> p;


	for (int i = 0; i < s.size(); i++)
	{
		s[i] = toupper(s[i]);

		if (s[i] == c)
			p.push_back(i);
	}

	for (int i = 1; i < p.size(); i++)
	{
		cout << p[i] - p[i - 1] << ' ';
	}

	return 0;
}
