#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, e;
    cin >> n >> e;

    //    int mat[n];//array

    vector<int> mat[n]; // adjacency list
    memset(mat, 0, sizeof(mat));
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    // int src;
    // cin >> src;
    // for (int x : mat[0])
    // {
    //     cout << x << " ";
    // }

    int test;
    cin >> test;
    while (test--)
    {
        int src;
        cin >> src;

        if (mat[src].size() == 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            vector<int> v;

            for (int i = 0; i < mat[src].size(); i++)
            {
                v.push_back(mat[src][i]);
            }
            sort(v.begin(), v.end(), greater<int>());
            for (auto val : v)
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    return 0;
}