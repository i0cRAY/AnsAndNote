#include <bits/stdc++.h>
using namespace std;

int n;

bool even(long long a)
{
    while (a > 0)
    {
        if ((a % 10) % 2 == 1) 
            return false;
        a /= 10;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;


        int l = (int)ceil(sqrt(pow(10, k - 1))); 
        int r = (int)floor(sqrt(pow(10, k) - 1));

        for (int i = l; i <= r; i++)
        {
            long long a = (long long)i * i;
            if (even(a))
            {
                cout << a << '\n';
                break;
            }
        }
    }

    return 0;
}
