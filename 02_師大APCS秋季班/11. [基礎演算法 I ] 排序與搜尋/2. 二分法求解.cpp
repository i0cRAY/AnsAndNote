#include <bits/stdc++.h>
using namespace std;

int main() {
    double a = 0, b = 1, m, fa, fm;
    const double EPS = 1e-7; 
    while (b - a > EPS) {
        m = (a + b) / 2;
        fa = 2 - exp(a);
        fm = 2 - exp(m);
        if (fa * fm < 0) b = m;
        else a = m;
    }
    cout << fixed << setprecision(6) << (a + b) / 2 << endl;
    return 0;
}
