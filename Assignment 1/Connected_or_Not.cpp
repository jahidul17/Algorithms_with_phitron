#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, e;
    cin >> n >> e;

    int mat[n][n];
    memset(mat, 0, sizeof(mat));

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        mat[a][b] = 1; // Assign directed graph
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int test;
    cin >> test;
    while (test--)
    {
        int a, b;
        cin >> a >> b;

        if (mat[a][b] == 1 || a == b)
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