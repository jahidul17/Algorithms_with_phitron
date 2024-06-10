#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Bottom Up Approch with loop

    int n;
    cin >> n;
    int a[n];
    a[0] = 0;
    a[1] = 1;

    // Time complexity O(n)
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    cout << a[n] << endl;

    return 0;
}