#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++)
    {       
        int ascii = (int)s[i];

        if (ascii >= 65 && ascii <= 90)
        {
            ascii += 13;
            
            if (ascii > 90)
                ascii = ascii - 90 + 64;
        }
        else if (ascii >= 97 && ascii <= 122)
        {
            ascii += 13;
            
            if (ascii > 122)
                ascii = ascii - 122 + 96;
        }

        s[i] = char(ascii);

        cout << s[i];
    }
   
    return 0;
}
