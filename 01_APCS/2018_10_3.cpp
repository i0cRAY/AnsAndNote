#include<iostream>
using namespace std;
string s; int n; int i;

int f(int n) {
	char c = s[i++];
	if (c == '1') { return n * n; }
	else if (c == '0') { return 0; }
	else { return f(n / 2) + f(n / 2) + f(n / 2) + f(n / 2); }
}

int main() {
	cin >> s >> n;
	cout << f(n);
}
