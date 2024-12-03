#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;

    stack<char> st;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push('(');
        }
        else
        {
            if (st.empty())
            {
                cout << 0;
                return;
            }
            else
            {
                cnt++;
                st.pop();
            }
        }
    }    
    
    if (st.empty())
    {
        cout << cnt;
    }
    else
    {
        cout << 0;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
   
    return 0;
}
