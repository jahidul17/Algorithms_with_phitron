#include <bits/stdc++.h>

using namespace std;
int knapsack(int n, int weight[], int value[], int W)
{
    if (n == 0 || W == 0)
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
    int n, W;
    cin >> n;
    int weight[n], value[n];
    cin >> W;

    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    cout << knapsack(n, weight, value, W) << endl;

    return 0;
}
