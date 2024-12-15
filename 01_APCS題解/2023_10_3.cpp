// 註 : 用 dfs 會 95%，所以我用 stack 代替遞迴
#include <bits/stdc++.h>
using namespace std;

/*
F: 右和下
H: 左和右
7: 左和下
I: 上和下
X: 上、下、左和右
L: 右和上
J: 左和上
0: 没有水管
*/

map<char, vector<bool>> pipe = {
    // 1 為開口， 0 反之
    // 上右下左
    {'F', {0, 1, 1, 0}},
    {'H', {0, 1, 0, 1}},
    {'7', {0, 0, 1, 1}},
    {'I', {1, 0, 1, 0}},
    {'X', {1, 1, 1, 1}},
    {'L', {1, 1, 0, 0}},
    {'J', {1, 0, 0, 1}},
    {'0', {0, 0, 0, 0}}
};

int dx[4] = { -1, 0, 1, 0 }; 
int dy[4] = { 0, 1, 0, -1 }; 

int n, m;
char a[505][505];
bool visited[505][505];

int dfs(int i, int j) {
    stack<pair<int, int>> st;
    st.push({ i, j });
    visited[i][j] = true;
    int size = 0;

    while (!st.empty()) {
        int x = st.top().first;
        int y = st.top().second;
        st.pop();
        size++;

        for (int d = 0; d < 4; d++) {
            int x_next = x + dx[d];
            int y_next = y + dy[d];

            if (x_next >= 0 && x_next < n && y_next >= 0 && y_next < m && !visited[x_next][y_next]) {
                if (pipe[a[x][y]][d] && pipe[a[x_next][y_next]][(d + 2) % 4]) {
                    visited[x_next][y_next] = true;
                    st.push({ x_next, y_next });
                }
            }
        }
    }

    return size;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && a[i][j] != '0') {
                mx = max(mx, dfs(i, j)); 
            }
        }
    }

    cout << mx;
    return 0;
}
