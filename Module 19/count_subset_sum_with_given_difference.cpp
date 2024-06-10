#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int a[n], sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int di;
    cin >> di;

    if ((di + sum) % 2 == 0)
    {
        int s = (di + sum) / 2;

        int dp[n + 1][s + 1];
        dp[0][0] = 1;

        for (int i = 1; i <= s; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (a[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // for (int i = 0; i <= n; i++)
        // {
        //     for (int j = 0; j <= s; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        cout << dp[n][s];
    }
    else
    {
        cout << "0";
    }

    return 0;
}

// 4
// 1 1 2 3
// 1

// output
// 1

// 4
// 1 1 2 3
// 2

// output
// 0

// 4
// 1 1 2 3
// 3

// output
// 2