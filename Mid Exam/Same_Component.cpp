#include <bits/stdc++.h>

using namespace std;
char a[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
long long int n, m;
long long int si, sj, di, dj;

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
bool found_dest = false;
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    if (si == di && sj == dj)
    {
        found_dest = true;
    }
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false && a[ci][cj] == '.')
        {

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

    cin >> si >> sj;
    cin >> di >> dj;
    found_dest = false;
    dfs(si, sj);

    if (found_dest == true)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}