#include <bits/stdc++.h>
using namespace std;

int n;

int f91(int N)
{
    if (N >= 101)
        return N - 10;
    else
        return f91(f91(N + 11));
}

int main()
{
    while (cin >> n && n != 0)
        cout << "f91(" << n << ") = " << f91(n) << "\n";

    return 0;
}
