#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, l = 0, r, c = 0, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cin >> x;
    r = n - 1;
    while (l <= r) {
        c++;
        m = (l + r) / 2;
        if (a[m] == x) {
            cout << m + 1 << " " << c << endl;
            return 0;
        }
        if (a[m] < x) {
          l = m + 1;
        }
        else r = m - 1;
    }
    cout << "not found " << c << endl;
    return 0;
}

