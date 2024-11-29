#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    while (cin >> n) {
        vector<int> prices(n);
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }
        cin >> m;
        cin.ignore();

        unordered_map<int, int> seen; 
        int best_i = -1, best_j = -1;
        int min_diff = numeric_limits<int>::max();

        for (int i = 0; i < n; i++) {
            int target = m - prices[i]; 
            if (seen.find(target) != seen.end()) {
                int j = seen[target];
                int diff = abs(prices[i] - target);
                if (diff < min_diff || (diff == min_diff && prices[i] < best_i)) {
                    best_i = min(prices[i], target);
                    best_j = max(prices[i], target);
                    min_diff = diff;
                }
            }
            seen[prices[i]] = i; 
        }

        cout << "Peter should buy books whose prices are " << best_i << " and " << best_j << ".\n\n";
    }
    return 0;
}
