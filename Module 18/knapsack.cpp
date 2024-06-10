#include <bits/stdc++.h>

using namespace std;
// Time complixity 2^n
int knapsack(int n, int weight[], int value[], int W)
{
    if (n < 0 || W == 0)
    {
        return 0;
    }
    if (weight[n] <= W)
    {
        // duita option
        // niye dekhbo, na niya dekhbo
        int op1 = knapsack(n - 1, weight, value, W - weight[n]) + value[n];
        int op2 = knapsack(n - 1, weight, value, W);

        return max(op1, op2);
    }
    else
    {
        // ekta option
        // na niyei dekhte hobe
        int op2 = knapsack(n - 1, weight, value, W);
        return op2;
    }
}

int main()
{
    int n;
    int weight[n], value[n];
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int W;
    cin >> W;

    cout << knapsack(n - 1, weight, value, W) << endl;

    return 0;
}
// input
// 4
// 2 3 4 5
// 1 3 5 3
// 8

// Output
// 8