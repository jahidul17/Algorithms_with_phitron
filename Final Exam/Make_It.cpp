#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
// map<ll, bool> dp;

ll dp[100005];

bool makeit(ll current_val, ll n)
{
    if (current_val == n)
    {
        return true;
    }
    if (current_val > n)
    {
        return false;
    }

    // if (dp.find(current_val) != dp.end())
    // {
    //     return dp[current_val];
    // }

    if (dp[current_val] != -1)
    {
        return dp[current_val];
    }

    bool op1 = makeit(current_val + 3, n);
    bool op2 = makeit(current_val * 2, n);

    return dp[current_val] = op1 || op2;
};

int main()
{

    ll test;
    cin >> test;

    while (test--)
    {
        ll n;
        cin >> n;

        // dp.clear();

        for (int i = 0; i < n; i++)
        {
            dp[i] = 0;
        }

        for (int j = 0; j <= n; j++)
        {
            dp[j] = -1;
        }

        if (makeit(1, n))
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

// #include <bits/stdc++.h>

// using namespace std;
// typedef long long ll;

// map<ll, bool> dp;

// bool makeit(ll current_val, ll res)
// {
//     if (current_val == res)
//         return true;
//     if (current_val > res)
//         return false;
//     if (dp.find(current_val) != dp.end())
//     {
//         return dp[current_val];
//     }
//     bool opt1 = makeit(current_val + 3, res);
//     bool opt2 = makeit(current_val * 2, res);
//     return dp[current_val] = opt1 || opt2;
// };

// int main()
// {
//     ll test;
//     cin >> test;
//     while (test--)
//     {
//         ll n;
//         cin >> n;
//         dp.clear(); // Clear the memoization map for each test case.

//         if (makeit(1, n))
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }

//     return 0;
// }
