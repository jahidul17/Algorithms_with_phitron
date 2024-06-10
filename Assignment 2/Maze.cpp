#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

char a[N][N];

int vis[N][N];
pair<int, int> path[N][N];
vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
int sx, sy, ex, ey;

bool isValid(int x, int y)
{
    return !vis[x][y] && (x >= 0) and (x < n) and (y >= 0) and (y < m);
}

void bfs()
{
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (auto mv : moves)
        {
            int new_x = x + mv.first;
            int new_y = y + mv.second;

            if (isValid(new_x, new_y) && a[new_x][new_y] != '#')
            {
                vis[new_x][new_y] = true;
                path[new_x][new_y] = {mv.first, mv.second};

                q.push({new_x, new_y});
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
            path[i][j] = {-1, -1};

            cin >> a[i][j];
            if (a[i][j] == 'R')
            {
                sx = i;
                sy = j;
            }
            if (a[i][j] == 'D')
            {
                ex = i;
                ey = j;
            }
        }
    }

    bfs();

    // When can not go
    if (!vis[ex][ey])
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
        return 0;
    }
    // When find shorest distance
    vector<pair<int, int>> ans;
    pair<int, int> dest = {ex, ey};

    while (dest.first != sx or dest.second != sy)
    {
        ans.push_back({path[dest.first][dest.second]});
        dest.first -= ans.back().first;
        dest.second -= ans.back().second;
    }

    reverse(ans.begin(), ans.end());

    ans.pop_back();

    int tx = sx;
    int ty = sy;
    for (auto i : ans)
    {
        tx = tx + i.first;
        ty = ty + i.second;

        a[tx][ty] = 'X';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}
