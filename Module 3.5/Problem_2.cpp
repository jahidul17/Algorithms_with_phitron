#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5; // 100000+5
vector<int> v[N];
bool vis[N];

void dfs(int src)
{
    cout << src << endl;
    vis[src] = true;

    for (int i = 0; i < v[src].size(); i++)
    {
        int child = v[src][i];
        if (vis[child] == false)

            dfs(child);
    }
}

int main()
{

    int n, e;
    cin >> n >> e;
    int ed = n;
    while (e--)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    // dfs(0); // source
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            dfs(i);
            count++;
            cout << "Component- " << count << endl;
        }
    }
    cout << "Final Component- " << count << endl;

    return 0;
}
