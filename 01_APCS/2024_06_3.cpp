#include <bits/stdc++.h>
using namespace std;

vector<char> a(100); 
int l;  
string arr;  
string s;  
unordered_set<string> s2;  
vector<string> a2;

void so(int index) {
    if (index == l) {
        string t;
        for (int i = 0; i < l; i++) {
            t += a[i];
        }
        a2.push_back(t);
        return;
    }
    for (int i = 0; i < arr.size(); i++) {
        a[index] = arr[i];
        so(index + 1);
    }
}

int main() {
    cin >> arr >> l >> s;
    so(0);

    // 生成所有可能的長度為 l 的子字符串
    for (int i = 0; i <= s.size() - l; i++) {
        string t = s.substr(i, l);
        s2.insert(t);
    }

    // 打印在 a2 中但不在 s2 中的组合
    for (const string& comb : a2) {
        if (s2.find(comb) == s2.end()) {
            cout << comb << endl;
            return 0;  
        }
    }
  
    return 0;
}
