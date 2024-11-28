#include <bits/stdc++.h>
using namespace std;

long long h[100005];
int parent[100005];
vector<int> child[100005];

void dfs(int p)
{
    for (auto c : child[p])
    {
        dfs(c);

        h[p] = max(h[p], h[c] + 1);
    }
}


void slove()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int c;
            cin >> c;
            child[i].push_back(c);
            parent[c] = i;
        }
    }

    int root = 0;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == 0)
        {
            root = i;
            break;
        }
    }           

    dfs(root);

    int total = 0;
    for (int i = 1; i <= n; i++)
        total += h[i];
    
    cout << root << '\n' << total;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    slove();
    return 0;
}
