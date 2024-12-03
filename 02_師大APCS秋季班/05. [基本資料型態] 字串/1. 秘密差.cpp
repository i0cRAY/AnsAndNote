#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int o = 0, e = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 0)
            e += s[i] - '0';
        else
            o += s[i] - '0';
    }

    cout << abs(e - o);
    return 0;
}
