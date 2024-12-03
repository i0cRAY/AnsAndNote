#include <bits/stdc++.h>
using namespace std;

vector<int> c[100005];

long long ans = 0;

int dfs(int parent)
{
    int mx = 0;
    int h = 0;

    for (auto child : c[parent])
    {
         h = dfs(child) + 1;
         mx = max(mx, h);
    }
    ans += mx;
    return mx;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;

        while (k--)
        {
            int child;
            cin >> child;

            p[child] = i;
            c[i].push_back(child);
        }
    }

    int root = 0;

    for (int i = 1; i <= n; i++)
    {
        if (p[i] == 0)
        {
            root = i;
            cout << i << '\n';
        }
        
    }

    dfs(root);

    cout << ans;

    return 0;
}
