#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int a[300005], pre[300005];
pair<int, int> st[4 * 300005];

#define lc 2 * node
#define rc 2 * node + 1
#define mid (l + r) / 2

void build(int node, int l, int r) {
    if (l == r) {
        st[node] = { a[l], l }; 
    }
    else {
        build(lc, l, mid);
        build(rc, mid + 1, r);
        st[node] = min(st[lc], st[rc]); 
    }
}

pair<int, int> query(int node, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) {
        return { INT_MAX, -1 }; 
    }
    if (ql <= l && qr >= r) {
        return st[node]; 
    }
    auto left = query(lc, l, mid, ql, qr);
    auto right = query(rc, mid + 1, r, ql, qr);
    return min(left, right); 
}

int get_sum(int l, int r) {
    if (l > r) { 
        return 0; 
    }
    return pre[r] - (l > 0 ? pre[l - 1] : 0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i] = a[i];
        if (i != 0) {
            pre[i] += pre[i - 1];
        }
    }

    build(1, 0, n - 1); 

    int l = 0, r = n - 1;
    while (l <= r) {
        if (l == r) {
            cout << a[l] << '\n';
            return 0;
        }

        auto m = query(1, 0, n - 1, l, r).second; 
        int left_sum = get_sum(l, m - 1); 
        int right_sum = get_sum(m + 1, r);

        if (m == l) {
            l = m + 1; // 最小值在左邊界
        }
        else if (m == r) {
            r = m - 1; // 最小值在右邊界
        }
        else {
            if (left_sum > right_sum) {
                r = m - 1; 
            }
            else {
                l = m + 1;
            }
        }
    }

    return 0;
}
