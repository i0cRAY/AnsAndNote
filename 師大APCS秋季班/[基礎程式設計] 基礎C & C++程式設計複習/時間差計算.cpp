#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string t1, t2;
    cin >> t1 >> t2;


    int h1 = (t1[0] - '0') * 10 + (t1[1] - '0');
    int h2 = (t2[0] - '0') * 10 + (t2[1] - '0');
    int m1 = (t1[3] - '0') * 10 + (t1[4] - '0');
    int m2 = (t2[3] - '0') * 10 + (t2[4] - '0');
    int s1 = (t1[6] - '0') * 10 + (t1[7] - '0');
    int s2 = (t2[6] - '0') * 10 + (t2[7] - '0');

    int h3 = h2 - h1;
    int m3 = m2 - m1;
    int s3 = s2 - s1;



    if (s3 < 0)
    {
        s3 += 60;
        m3--;
    }
    if (m3 < 0)
    {
        m3 += 60;
        h3--;
    }
    if (h3 < 0)
    { 
        h3 += 24;
    }
        

    cout << setfill('0') << setw(2) << h3 << ':' << setfill('0') << setw(2) << m3 << ':' << setfill('0') << setw(2) << s3;

    return 0;
}
