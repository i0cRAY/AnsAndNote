#include <bits/stdc++.h>
using namespace std;

int h[100005], d;
bool notRoot[100005];
vector<int> child[100005];

void dfs(int p)
{
    for (auto c : child[p])
    {
        dfs(c);
        
        d = max(d, h[c] + 1 + h[p]);
        h[p] = max(h[p], h[c] + 1);
    }

}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        notRoot[b] = true;
        child[a].push_back(b);
    }

    int root = 0;
    while (notRoot[root]) 
        root++;

    dfs(root);

    cout << d;
    return 0;
}
