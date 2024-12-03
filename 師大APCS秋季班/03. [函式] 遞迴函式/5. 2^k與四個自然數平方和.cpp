#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    int target = pow(2, k);
    bool found = false;


    for (int p = 1; p * p <= target; p++)
    {
        for (int q = p; p * p + q * q <= target; q++)
        {
            for (int r = q; p * p + q * q + r * r <= target; r++)
            {
                int s1 = target - (p * p + q * q + r * r);
                int s = sqrt(s1);

                if (s >= r && s * s == s1) {
                    cout << p << ' ' << q << ' ' << r << ' ' << s << '\n';
                    found = true;
                }
            }
        }
    }


    if (!found)
        cout << "0" << '\n';

    return 0;
}
