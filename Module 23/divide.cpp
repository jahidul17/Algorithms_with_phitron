#include <bits/stdc++.h>
using namespace std;
void divide(int a[], int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    if (l < r)
    {
        int mid = (l + r) / 2;
        divide(a, l, mid);
        divide(a, mid + 1, r);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    divide(a, 0, n - 1);
    return 0;
}

// 6
// 10 20 30 40 50 60

// output
// 10 20 30 40 50 60
// 10 20 30
// 10 20
// 10
// 20
// 30
// 40 50 60
// 40 50
// 40
// 50
// 60

// input
// 10
// 2 3 5 10 1 4 6 8 9 15

// output
// 2 3 5 10 1 4 6 8 9 15
// 2 3 5 10 1
// 2 3 5
// 2 3
// 2
// 3
// 5
// 10 1
// 10
// 1
// 4 6 8 9 15
// 4 6 8
// 4 6
// 4
// 6
// 8
// 9 15
// 9
// 15
