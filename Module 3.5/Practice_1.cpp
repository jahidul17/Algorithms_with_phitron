#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5; // 100000+5
vector<int> v[N];
bool vis[N];

int cnt = 1;
int dfs(int src)
{

    // cout << src << endl;
    vis[src] = true;

    for (int child : v[src])
    {
        if (vis[child] == false)
        { // Check visit or not
            dfs(child);
            cnt++;
        }
    }

    return cnt;
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

    memset(vis, false, sizeof(vis));

    int src;
    cin >> src;
    dfs(src);

    cout << cnt << endl;

    return 0;
}
