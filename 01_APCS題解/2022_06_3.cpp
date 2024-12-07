#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    set<pair<int, int>> x_st, y_st;
    map<pair<int, int>, int> t_mp;

    for (int i = 0; i < n; i++) {
        int x, y, t;
        cin >> x >> y >> t;

        x_st.insert({x, y});
        y_st.insert({y, x});
        t_mp[{x, y}] = t;
    }
    y_st.insert({0, 0});

    int d = 4;
    int x_now = 0, y_now = 0, cnt = 0;

    while (true) {
        if (d == 1) {
            auto now = x_st.find({x_now, y_now});
            auto nxt = now; nxt++;

            if (nxt == x_st.end() || nxt->first != now->first) {
                break;
            }
            else {
                int x_nxt = nxt->first;
                int y_nxt = nxt->second;
                x_now = x_nxt;
                y_now = y_nxt;

                (t_mp[{x_nxt, y_nxt}] == 0) ? d = 4 : d = 3;
            }
        }
        else if (d == 2) {
            auto now = x_st.find({x_now, y_now});
            auto nxt = now; nxt--;

            if (now == x_st.begin() || nxt->first != now->first) {
                break;
            }
            else {
                int x_nxt = nxt->first;
                int y_nxt = nxt->second;
                x_now = x_nxt;
                y_now = y_nxt;

                (t_mp[{x_nxt, y_nxt}] == 0) ? d = 3 : d = 4;
            }
        }
        else if (d == 3) {
            auto now = y_st.find({y_now, x_now});
            auto nxt = now; nxt--;

            if (now == y_st.begin() || nxt->first != now->first) {
                break;
            }
            else {
                int y_nxt = nxt->first;
                int x_nxt = nxt->second;
                x_now = x_nxt;
                y_now = y_nxt;

                (t_mp[{x_nxt, y_nxt}] == 0) ? d = 2 : d = 1;
            }
        } 
        else {
            auto now = y_st.find({y_now, x_now});
            auto nxt = now; nxt++;

            if (nxt == y_st.end() || nxt->first != now->first) {
                break;
            }
            else {
                int y_nxt = nxt->first;
                int x_nxt = nxt->second;
                x_now = x_nxt;
                y_now = y_nxt;

                (t_mp[{x_nxt, y_nxt}] == 0) ? d = 1 : d = 2;
            }

            y_st.erase({0, 0});
        }
        cnt++;
    }

    cout << cnt;
    return 0;
}
