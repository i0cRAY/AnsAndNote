#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, l; cin >> n >> l;
    int c[100005] = {}; int h[100005] = {};
    c[0] = 0; c[n + 1] = l; h[0] = 1e9; h[n + 1] = 1e9;
    for (int i = 1; i <= n; i++) { cin >> c[i]; }
    for (int i = 1; i <= n; i++) { cin >> h[i]; }
    stack<int> s; s.push(0); int total = 0; int highest = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i] - h[i] >= c[s.top()] or c[i] + h[i] <= c[i + 1]) {
            total++; highest = max(highest, h[i]);
            while (c[s.top()] + h[s.top()] <= c[i + 1]) {
                total++; highest = max(highest, h[s.top()]);
                s.pop();
            }
        }
        else {
            s.push(i);
        }
    }
    cout << total << endl << highest;
}
