#include <bits/stdc++.h>

using namespace std;
vector<int> v[1005];
bool vis[1005];

vector<int> rev;
void bfs(int src, int L)
{

    queue<pair<int, int>> q;
    q.push({src, 0});
    vis[src] = true;

    bool paisi = false;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int par = p.first;
        int level = p.second;
        // cout << par << endl;

        if (L == level)
        {
            rev.push_back(par);
        }

        for (auto child : v[par])
        {
            if (vis[child] == false)
            {
                q.push({child, level + 1});
                vis[child] = true;
            }
        }
    }
    // if (paisi == false)
    // {
    //     cout << -1 << endl;
    // }
}

int main()
{

    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int L;
    cin >> L;
    memset(vis, false, sizeof(vis));

    bfs(0, L);

    // Print
    reverse(rev.begin(), rev.end());

    for (auto node : rev)
    {
        cout << node << " ";
    }

    return 0;
}