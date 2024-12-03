# LCA (using Binary Lifting)

## 實作

### 求層數

進行 DFS 遍歷整棵樹

```c++
int dfs(int p, int d)
{
    visited[p] = true;
    dep[p] = d;

    for (auto c : child[p]) 
    {
        if (!visited[c]) 
        {
            parent[c][0] = p;
            dfs(c, d + 1);
        }
    }

    return 0;
}
```

### 找出每個節點的 $2^j$ 倍祖先

定義 `parent[i][j]` 為節點 $i$ 的第 $2^j$ 倍祖先

對於 `parent[i][j]` :

- `parent[i][0]` = 節點 $i$ 的直接父節點

- `parent[i][j]` = `parent[parent[i][j - 1]][j - 1]`

  意思是說 : 節點 $i$ 的 $2^i$ 祖先，可以通過 $i$ 的 $2^{j-1}$ 祖先的 $2^{j-1}$ 祖先來找到

```c++
for (int j = 1; j < 20; j++) 
{
    for (int i = 0; i < n; i++) 
    {
        if (parent[i][j - 1] != -1)
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        else
            parent[i][j] = -1;
    }
}
```

### 利用倍增法求兩點的 LCA

函式 `lca` 接收參數 $a$ 與 $b$ 並計算他們的 LCA

步驟 :

1. 讓 $b$ 成為較深的節點，確保調整時是將較深的節點向上移動
2. 若兩者深度不同，將 $b$ 向上移動至與 $a$ 相同深度
3. 若調整後 $a$ 和 $b$ 已經相同，則回傳此節點即為 LCA
4. 從高位開始，逐步比較雙方的祖先，若不同則同時向上移動

```c++
int lca(int a, int b) 
{
    // 讓 b 成為較深的節點，確保調整時是將較深的節點向上移動
    if (dep[b] < dep[a]) swap(a, b);

    // 若兩者深度不同，將 b 向上移動至與 a 相同深度
    if (dep[a] != dep[b]) 
    {
        int dif = dep[b] - dep[a];       
        for (int j = 0; j < 20; j++) 
        	if (dif & (1 << j))
            	b = parent[b][j];
    }

    // 若調整後 a 和 b 已經相同，則回傳此節點即為 LCA
    if (a == b) 
        return a;
    
    // 從高位開始，逐步比較雙方的祖先，若不同則同時向上移動
    for (int i = 19; i >= 0; i--) 
    {
        if (parent[a][i] != parent[b][i]) 
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    
    return parent[a][0];
}
```

## 例題

### P3379【模板】最近公共祖先（LCA）

[洛谷-P3379](https://www.luogu.com.cn/problem/P3379)

```c++
#include <bits/stdc++.h>
using namespace std;

vector<int> child[500005];
int dep[500005], parent[500005][20];
bool visited[500005];

int dfs(int p, int d)
{
    visited[p] = true;
    dep[p] = d;

    for (auto c : child[p]) 
    {
        if (!visited[c]) 
        {
            parent[c][0] = p;
            dfs(c, d + 1);
        }
    }

    return 0;
}

int lca(int a, int b) 
{
    if (dep[b] < dep[a])
        swap(a, b);

    int dif = dep[b] - dep[a];
    for (int j = 0; j < 20; j++) 
        if (dif & (1 << j))
            b = parent[b][j];

    if (a == b)
        return a;

    for (int i = 19; i >= 0; i--) 
    {
        if (parent[a][i] != parent[b][i]) 
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, S;
    cin >> N >> M >> S;

    for (int t = 0; t < N - 1; t++) 
    {
        int x, y;
        cin >> x >> y;

        child[x].push_back(y);
        child[y].push_back(x);
    }

    dfs(S, 0);

    for (int j = 1; j < 20; j++) 
        for (int i = 1; i <= N; i++) {
            if (parent[i][j - 1] != -1)
                parent[i][j] = parent[parent[i][j - 1]][j - 1];

    while (M--) 
    {
        int a, b;
        cin >> a >> b;

        cout << lca(a, b) << '\n';
    }

    return 0;
}
```

### 1687 . 樹上詢問 (Query on a Tree II)

[TIOJ-1687](https://tioj.ck.tp.edu.tw/problems/1687)

```c++
#include <bits/stdc++.h>
using namespace std;

int dep[100005], parent[100005][20];
bool visited[100005];
vector<int> child[100005];


void dfs(int p, int d) {
    visited[p] = true;
    dep[p] = d + 1;

    for (auto c : child[p])
    {
        if (!visited[c]) 
        {
            parent[c][0] = p;
            dfs(c, d + 1);
        }
    }
}


int moveUp(int n, int k) 
{
    for (int i = 0; i < 20 && k > 0; i++) 
    {
        if (k & 1)
            n = parent[n][i];
        k >>= 1;

        if (n == -1) break; // 防止走出樹外
    }
    return n;
}


int findLCA(int s, int e) 
{
    if (dep[e] < dep[s])
        swap(s, e);

    // 將 e 提升到與 s 相同深度
    int dif = dep[e] - dep[s];
    for (int j = 0; j < 20; j++)
        if (dif & (1 << j))
            e = parent[e][j];

    if (s == e) 
        return s;

    // 同時提升 s 和 e，直到找到共同祖先
    for (int i = 19; i >= 0; i--) 
    {
        if (parent[s][i] != parent[e][i])
        {
            s = parent[s][i];
            e = parent[e][i];
        }
    }

    return parent[s][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        child[a].push_back(b);
        child[b].push_back(a);
    }

    dfs(1, 0);

    for (int j = 1; j < 20; j++)
        for (int i = 1; i <= n; i++) 
            parent[i][j] = parent[parent[i][j - 1]][j - 1];

    while (q--) 
    {
        int start, end, k;
        cin >> start >> end >> k;

        int LCA = findLCA(start, end);
        int dS = dep[start] - dep[LCA];
        int dE = dep[end] - dep[LCA];
        int totalD = dS + dE;

        if (k > totalD)
            cout << -1 << '\n';
        else if (k <= dS) 
        {
            // 在 start 到 LCA 的路徑上
            cout << moveUp(start, k) << '\n';
        }
        else 
        {
            // 在 LCA 到 end 的路徑上
            cout << moveUp(end, dE - (k - dS)) << '\n';
        }
    }
    return 0;
}
```

### 2172 . 物種演化 (Evolution)

[TIOJ-2172](https://tioj.ck.tp.edu.tw/problems/2172)

```c++
#include <bits/stdc++.h>
using namespace std;

int dep[100005], parent[100005][20];
bool visited[100005];
vector<int> child[100005];

void dfs(int p, int d)
{
    visited[p] = true;
    dep[p] = d;

    for (auto c : child[p])
    {
        if (!visited[c])
        {
            parent[c][0] = p;
            dfs(c, d + 1);
        }
    }
}

int lca(int x, int y) 
{
    if (dep[y] < dep[x])
        swap(x, y);

    int d = dep[y] - dep[x];

    for (int i = 0; i < 20; i++)
        if (d & (1 << i))
            y = parent[y][i];

    if (x == y)
        return x;

    for (int i = 19; i >= 0; i--) 
    {
        if (parent[x][i] != parent[y][i])
        {
            x = parent[x][i];
            y = parent[y][i];
        }
    }

    return parent[x][0];
}
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int t = 0; t < n - 1; t++)
    {
        int i, j;
        cin >> i >> j;

        child[i].push_back(j);
        child[j].push_back(i);
    }

    dfs(0, 0);

    for (int j = 1; j < 20; j++) 
    {
        for (int i = 0; i < n; i++) 
        {
            if (parent[i][j - 1] != -1)
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            else
                parent[i][j] = -1;
        }
    }

    while (m--)
    {
        int x, y;
        cin >> x >> y;

        int LCA = lca(x, y);
        cout << dep[x] + dep[y] - 2 * dep[LCA] << '\n'; 
    }

    return 0;
}
```
