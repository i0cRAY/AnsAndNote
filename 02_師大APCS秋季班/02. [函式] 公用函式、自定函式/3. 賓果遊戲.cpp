#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, bool>>> a(5, vector<pair<int, bool>>(5, {0, false}));
int x, y, mx = -1;

int score(int i, int j)
{
    int total = 0;

    // 直
    bool can = true;
    for (int c = i + 1; c < 5; c++)
        if (!a[c][j].second)
            can = false;
    for (int c = i - 1; c >= 0; c--)
        if (!a[c][j].second)
            can = false;
    if (can)
        total++;
    // 橫
    can = true;
    for (int c = j + 1; c < 5; c++)
        if (!a[i][c].second)
            can = false;
    for (int c = j - 1; c >= 0; c--)
        if (!a[i][c].second)
            can = false;
    if (can)
        total++;
    // 斜
    can = true;
    // 右
    if (i == j)
    {
        for (int r = i + 1, c = j + 1; c < 5; r++, c++)
            if (!a[r][c].second)
                can = false;     
        for (int r = i - 1, c = j - 1; c >= 0; r--, c--)
            if (!a[r][c].second)
                can = false;

        if (can)
            total++;
    }
    // 左
    else if (i + j == 4)
    {
        for (int r = i - 1, c = j + 1; r >= 0, c < 5; r--, c++)
            if (!a[r][c].second)
                can = false;
        for (int r = i + 1, c = j - 1; r > 5, c >= 0; r++, c--)
            if (!a[r][c].second)
                can = false;

        if (can)
            total++;
    }

    return total;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> a[i][j].first;

    int n = 0;
    while (n != -1)
    {
        cin >> n;

        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
            {
                if (a[i][j].first == n)
                {
                    a[i][j].second = true;
                    break;
                }
            }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (!a[i][j].second)
            {
                if (mx == score(i, j))
                {
                    if (a[x][y].first > a[i][j].first)
                    {
                        mx = score(i, j);
                        x = i, y = j;
                    }
                }
                else if (mx < score(i, j))
                {
                    mx = score(i, j);
                    x = i, y = j;
                }
            }
        }
    }


    cout << a[x][y].first;
    return 0;
}
