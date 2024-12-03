#include <bits/stdc++.h>
using namespace std;

struct wf { int w, f; };

wf a[100005];

// w 大在後面， f 大在前面
bool cmp(wf p, wf q) { return p.w * q.f < q.w * p.f; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i].w;
    for (int i = 0; i < n; i++)
        cin >> a[i].f;

    sort(a, a + n, cmp);

    long long t = 0;
    long long ans = 0;

    for (int i = 1; i < n; i++)
    {
        t += a[i - 1].w;
        ans += t * a[i].f;
    }

    cout << ans;

    return 0;
}
