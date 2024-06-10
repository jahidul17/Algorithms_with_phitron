#include <bits/stdc++.h>

using namespace std;
char a[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
long long int res;
long long int n, m;

vector<int> v;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void dfs(int si, int sj)
{

    // cout << si << " " << sj << endl;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false && a[ci][cj] == '.')
        {
            res++;
            dfs(ci, cj);
        }
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.' && vis[i][j] == false)
            {
                res = 1;
                dfs(i, j);
                v.push_back(res);
            }
        }
    }

    if (v.empty())
    {
        cout << "0";
    }
    else
    {
        sort(v.begin(), v.end());
        for (int val : v)
        {
            cout << val << " ";
        }
    }
}
