#include <bits/stdc++.h>
using namespace std;

int findIndex(vector<int> a, int book, int index) {
    for (int i = index + 1; i < a.size(); i++) {
        if (a[i] == book) {
            return i;
        }
    }
    return a.size(); 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n;

    vector<int> days;
    int t;
    while (cin >> t) {
        days.push_back(t);
        if (cin.peek() == '\n') {
            break;
        }
    }
    cin >> k;

    set<int> bag;
    int cnt = 0;

    for (int i = 0; i < days.size(); i++) {
        int book = days[i];

        if (bag.count(book)) { 
            continue; 
        }

        // 如果背包未滿，直接加入
        if (bag.size() < k) {
            bag.insert(book);
        } else {
            // 背包已滿，選擇替換
            int out = -1, outIndex = -1;
            for (auto b : bag) {
                int nextUse = findIndex(days, b, i);
                if (nextUse > outIndex) {
                    outIndex = nextUse;
                    out = b;
                }
            }

            bag.erase(out);
            bag.insert(book);
            cnt++;
        }
    }

    cout << cnt ;
    return 0;
}
