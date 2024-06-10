#include <bits/stdc++.h>

using namespace std;

int main()
{

    int test;
    cin >> test;

    while (test--)
    {

        int n;
        cin >> n;

        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }

        sort(a, a + n, greater<int>());

        for (int i = 0; i < n; i++)
        {
            if (a[0] == b[i] || a[1] == b[i])
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}