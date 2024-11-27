#include <bits/stdc++.h>
using namespace std;

int different(string s) {
    int cnt = 0;
    bool seen[26] = { false };
    for (int i = 0; i < s.size(); i++) {
        int a = s[i] - 'A';
        if (!seen[a]) {
            seen[a] = true;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;

    string best;
    cin >> best;
    int d = different(best);
    n--;

    while (n--) {
        string s;
        cin >> s;
        int sd = different(s);

        // cout << s << ' ' << sd << '\n';

        if (sd < d || (sd == d && s < best)) {
            d = sd;
            best = s;
        }
    } 

    cout << best;
    return 0;
}
