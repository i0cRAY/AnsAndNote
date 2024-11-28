#include <iostream>
#include <vector>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<vector<int>> matrix(n, vector<int>(n));
        vector<int> rowSum(n, 0), colSum(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
                rowSum[i] += matrix[i][j];
                colSum[j] += matrix[i][j];
            }
        }

        // 找出哪些行和列不符合偶同位性質
        int rowErr = -1, colErr = -1;
        int rowErrCount = 0, colErrCount = 0;

        for (int i = 0; i < n; i++) {
            if (rowSum[i] % 2 != 0) {
                rowErr = i;
                rowErrCount++;
            }
            if (colSum[i] % 2 != 0) {
                colErr = i;
                colErrCount++;
            }
        }

        if (rowErrCount == 0 && colErrCount == 0) {
            cout << "OK" << endl;
        } else if (rowErrCount == 1 && colErrCount == 1) {
            cout << "Change bit (" << rowErr + 1 << "," << colErr + 1 << ")" << endl;
        } else {
            cout << "Corrupt" << endl;
        }
    }

    return 0;
}
