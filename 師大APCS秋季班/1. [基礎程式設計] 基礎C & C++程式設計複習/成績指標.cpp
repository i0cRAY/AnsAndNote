#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';

    auto it = lower_bound(a.begin(), a.end(), 60);
    auto i = it - a.begin();

    if (i == 0)
        cout << "best case" << '\n';
    else
        cout << a[i - 1] << '\n';

    if (it == a.end())
        cout << "worst case";
    else
        cout << a[i];

    return 0;
}
