#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> c[200005]; 
long long num[200005], in[10005]; 

long long dfs(int p) 
{
    if (c[p].empty())
        return num[p];

    num[p] = 0;
    for (auto ch : c[p]) 
        num[p] += dfs(ch);

    return num[p];
}

void dfs2(int p, long long w)
{
    if (c[p].empty()) 
    {
        num[p] += w;
        cout << p << ' ';
        return;
    }

    int l = c[p][0];
    int r = c[p][1];

    if (num[l] <= num[r])
    {
        dfs2(l, w);
        num[p] += w;
    }
    else 
    {
        dfs2(r, w);
        num[p] += w;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = n; i <= 2 * n - 1; i++) 
        cin >> num[i];

    for (int i = 0; i < m; i++) 
        cin >> in[i];

    vector<int> f(2 * n + 5);
    for (int i = 1; i < n; i++) {
        int p, s, t;
        cin >> p >> s >> t;
        c[p].push_back(s);
        c[p].push_back(t);
        f[s] = p, f[t] = p;
    }

    int root;
    for (int i = 1; i < n; i++)
    {
        if (f[i] == 0)
        {
            root = i;
            break;
        }
    }
    
    dfs(root);
    for (int i = 0; i < m; i++) 
        dfs2(root, in[i]);

    return 0;
}
