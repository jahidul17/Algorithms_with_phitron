#include <bits/stdc++.h>

using namespace std;
// Problem One for practice
vector<int> v[1005];
bool vis[1005];
void bfs(int src, int dest)
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

        if (par == dest)
        {
            cout << level << endl;
            paisi = true;
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
    if (paisi == false)
    {
        cout << -1 << endl;
    }
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

    int Q;
    cin >> Q;

    while (Q--)
    {
        int src, dest;
        cin >> src >> dest;
        memset(vis, false, sizeof(vis));

        bfs(src, dest);
    }

    return 0;
}

// // input
// // 10 10
// // 0 1
// // 1 2
// // 0 4
// // 1 3
// // 2 0
// // 3 4
// // 1 5
// // 3 6
// // 7 8
// // 8 9
// // 8