#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<ll, bool> dp;

bool knapsack(ll s, ll res)
{
    if (s == res)
        return true;
    if (s > res)
        return false;
    if (dp.find(s) != dp.end())
    {
        return dp[s];
    }
    bool opt1 = knapsack(s * 10, res);
    bool opt2 = knapsack(s * 20, res);
    return dp[s] = opt1 || opt2;
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        dp.clear(); // Clear the memoization map for each test case.

        if (knapsack(1, n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}