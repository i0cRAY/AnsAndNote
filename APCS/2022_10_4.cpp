#include <bits/stdc++.h>
using namespace std;

int n, ans1 = 0, ans2 = 0;
int a[305][305], visited[305][305];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct s {
    int x, y, dist;
};

bool bfs(int h) {
    memset(visited, 0, sizeof(visited));  
    queue<s> q;
    q.push({0, 0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        s cur = q.front();
        q.pop();

        int x = cur.x, y = cur.y, dist = cur.dist;

        if (x == n - 1 && y == n - 1) {
            ans2 = dist; 
            return true;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                if (abs(a[x][y] - a[nx][ny]) <= h) {
                    visited[nx][ny] = true;
                    q.push({nx, ny, dist + 1});
                }
            }
        }
    }

    return false; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int l = 0, r = 1e6;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (bfs(mid)) {
            ans1 = mid;  
            r = mid - 1;
        } else {
            l = mid + 1; 
        }
    }

    cout << ans1 << '\n' << ans2;
    return 0;
}
