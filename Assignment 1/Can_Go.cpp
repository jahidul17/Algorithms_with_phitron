#include <bits/stdc++.h>

using namespace std;
char a[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

long long int n, m;
long long int ai, aj;
long long int bi, bj;
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
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false && a[ci][cj] != '#')
        {
            if (a[ci][cj] == '.' || a[ci][cj] == 'B')
            {
                dfs(ci, cj);
            }
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
            if (a[i][j] == 'A')
            {
                ai = i;
                aj = j;
            }
            if (a[i][j] == 'B')
            {
                bi = i;
                bj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    dfs(ai, aj);

    if (vis[bi][bj] == true)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
