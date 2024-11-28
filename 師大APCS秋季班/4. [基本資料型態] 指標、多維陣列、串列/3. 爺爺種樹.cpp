#include <bits/stdc++.h>
using namespace std;

int a[505][505]; 
int r, c, n;    


int f(int x1, int y1, int x2, int y2)
{
    if (x1 == x2)
        return 1;  // 橫排
    else if (y1 == y2)
        return 2;  // 直排
    else if ((x1 - y1) == (x2 - y2))
        return 3;  // 右上到左下
    else
        return 4;  // 左上到右下
}

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);           

    cin >> r >> c >> n;     

    while (n--)              
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1--, y1--, x2--, y2--;

        int w = f(x1, y1, x2, y2); 

        if (w == 1)                 // 橫排
            for (int j = min(y1, y2); j <= max(y1, y2); j++)
                a[x1][j]++;
        else if (w == 2)            // 直排
            for (int i = min(x1, x2); i <= max(x1, x2); i++)
                a[i][y1]++;
        else if (w == 3)            // 右上到左下
            for (int i = min(x1, x2), j = min(y1, y2); i <= max(x1, x2); i++, j++)
                a[i][j]++;
        else                        // 左上到右下
            for (int i = min(x1, x2), j = max(y1, y2); i <= max(x1, x2); i++, j--)
                a[i][j]++;
    }

    long long ans = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (a[i][j] > 0)
                ans++;

    cout << ans << '\n'; 
    return 0;
}
