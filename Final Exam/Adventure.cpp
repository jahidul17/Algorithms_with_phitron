#include <bits/stdc++.h>

using namespace std;
const int maxN = 1005;
const int maxW = 1005;
int dp[maxN][maxW];

int kanpsack(int n, int weight[], int value[], int w)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (weight[n - 1] <= w)
    {
        int op1 = kanpsack(n - 1, weight, value, w - weight[n - 1]) + value[n - 1];
        int op2 = kanpsack(n - 1, weight, value, w);

        return dp[n][w] = max(op1, op2);
    }
    else
    {
        int op2 = kanpsack(n - 1, weight, value, w);
        return op2;
    }
}

int main()
{
    int test;
    cin >> test;

    while (test--)
    {

        int n, w;
        cin >> n >> w;
        int weight[n], value[n];

        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> value[i];
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                dp[i][j] = -1;
            }
        }

        cout << kanpsack(n, weight, value, w) << endl;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << weight[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << value[i] << " ";
    // }

    return 0;
}
