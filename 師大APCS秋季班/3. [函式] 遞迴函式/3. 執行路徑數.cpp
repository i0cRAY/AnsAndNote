#include <bits/stdc++.h>
using namespace std;

unsigned long long f() {
    string x;
    unsigned long long ans = 1, a, b;

    while (cin >> x) {
        if (x == "S")
            continue;
        if (x == "IF")
        {
            a = f();
            b = f();
            ans = ans * (a + b);
        }
        else 
            return ans;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) 
        cout << f() << endl;

    return 0;
}
