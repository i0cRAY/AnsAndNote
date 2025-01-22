#include <bits/stdc++.h>
#define int long long
using namespace std;

int p[50005];

int cut(int l, int r) {
    if (l == r - 1) {
        return 0;
    }

    int t = (p[r] + p[l]) / 2;
    int m = l;

    while (p[m] < t) {
        m++;
    }
    if (p[m - 1] - p[l] >= p[r] - p[m]) {
        m--;
    }

    return p[r] - p[l] + cut(l, m) + cut(m, r);
}

signed main() {
    int N, L;
    cin >> N >> L;

    p[0] = 0;
    p[N + 1] = L;
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
    }

    cout << cut(0, N + 1);
    return 0;
}
