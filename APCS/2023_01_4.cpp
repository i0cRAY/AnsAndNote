#include <bits/stdc++.h>
using namespace std;

struct st { 
    int s, e;
};

bool cmp(st p, st q) {
    if (p.e == q.e) {
        return p.s < q.s;
    }
    return p.e < q.e;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<st> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].s;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].e;
    }

    sort(a.begin(), a.end(), cmp); 

    multiset<int> m; 
    for (int i = 0; i < k; i++) {
        m.insert(-1); 
    }

    int cnt = 0; 

    for (const auto& activity : a) {
        // 找到第一個空閒時間不晚於活動開始時間的機器
        auto it = m.lower_bound(activity.s);
        if (it != m.begin()) {
            --it; 
            m.erase(it);
            m.insert(activity.e); 
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}