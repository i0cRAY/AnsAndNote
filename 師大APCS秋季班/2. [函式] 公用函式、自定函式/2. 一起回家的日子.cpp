#include <bits/stdc++.h>
using namespace std;

int n, y, m, d;
int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string date;

bool leap(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;

    return false;
}

void add_days(int days)
{
    while (days > 0) {
        // 判斷當前年份是否為閏年
        bool is_leap_year = leap(y);
        // 調整二月的天數
        int current_month_days = month[m];
        if (is_leap_year && m == 2)
            current_month_days = 29;

        // 計算當前月份剩餘的天數
        int remaining_days = current_month_days - d;

        if (days > remaining_days) {
            // 移動到下個月
            days -= (remaining_days + 1);
            d = 1;
            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }
        else {
            d += days;
            days = 0;
        }
    }
    printf("%04d/%02d/%02d\n", y, m, d);
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int lcm(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;

    return abs(a * b) / gcd(a, b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    cin >> date;

    y = 1000 * (date[0] - '0') + 100 * (date[1] - '0') + 10 * (date[2] - '0') + (date[3] - '0');
    m = 10 * (date[5] - '0') + (date[6] - '0');
    d = 10 * (date[8] - '0') + (date[9] - '0');

    int l = c[0];
    for (int i = 1; i < n; i++)
    {
        l = lcm(l, c[i]);
    }

    add_days(l);

    return 0;
}
