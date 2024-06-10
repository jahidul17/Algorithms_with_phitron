#include <bits/stdc++.h>

using namespace std;

vector<int> v[1005];
bool vis[1005];
void bfs(int src)
{

    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << endl;
        // for (int i = 0; i < v[par].size(); i++)
        // {
        //     int child = v[par][i];
        //     cout << child << endl;
        // }
        // Or
        // for (auto child : v[par])
        // {
        //     cout << child << endl;
        // }
        for (auto child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
            }
        }
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

    int src;
    cin >> src;
    memset(vis, false, sizeof(vis));
    bfs(src);

    return 0;
}

// intput
// 5 6
// 0 1
// 1 2
// 0 4
// 1 3
// 2 0
// 3 4
// 0
