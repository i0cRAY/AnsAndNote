#include <bits/stdc++.h>
using namespace std;

int f(int a, int b, char c)
{
    if (c == '+')
        return a + b;
    else if (c == '-')
        return a - b;
    else if (c == '*')
        return a * b;
    else if (c == '/')
        return a / b;
    else
        return a % b;
}

void solve()
{
    string s;
    while (cin >> s)
    {
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%')
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(f(a, b, s[i]));         
            }
            else
            {
                st.push(s[i] - '0');
            }
        }
        cout << st.top() << '\n';
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
   
    return 0;
}
