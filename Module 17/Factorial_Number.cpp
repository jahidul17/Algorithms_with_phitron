#include <bits/stdc++.h>

using namespace std;

int fact(int n)
{

    if (n == 0)
    {
        return 1;
    }

    // int ans = n * fact(n - 1);
    int smallfact = fact(n - 1);
    int ans = n * smallfact;
    // cout << ans << endl;
    return ans;
}

int main()
{

    int n;
    cin >> n;
    int result = fact(n);

    cout << result;

    return 0;
}