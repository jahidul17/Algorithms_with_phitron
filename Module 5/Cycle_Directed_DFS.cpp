// #include <bits/stdc++.h>

// using namespace std;

// const int N = 1e5 + 5;
// bool vis[N];
// bool pathVis[N];
// vector<int> adj[N];
// bool ans;

// void Dfs(int parent)
// {

//     vis[parent] = true;
//     pathVis[parent] = true;
//     // cout << parent << endl;

//     for (int child : adj[parent])
//     {
//         if (pathVis[child])
//         {
//             ans = true;
//         }
//         if (!vis[child])
//         {
//             Dfs(child);
//         }
//     }
//     // Kaj sesh
//     pathVis[parent] = false;
// }

// int main()
// {

//     int n, e;
//     cin >> n, e;

//     while (e--)
//     {
//         int a, b;
//         cin >> a >> b;

//         adj[a].push_back(b);
//         // adj[b].push_back(a);
//     }

//     memset(vis, false, sizeof(vis));
//     memset(pathVis, false, sizeof(pathVis));

//     ans = false;
//     for (int i = 0; i < n; i++)
//     {
//         if (!vis[i])
//         {
//             Dfs(i);
//         }
//     }

//     if (ans)
//     {
//         cout << "Cycle Detected";
//     }
//     else
//     {
//         cout << "Cycle Not Detected";
//     }

//     return 0;
// }

// Phitron code

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
bool pathVisit[N];
vector<int> adj[N];
bool ans;
void dfs(int parent)
{
    vis[parent] = true;
    pathVisit[parent] = true;
    for (int child : adj[parent])
    {
        if (pathVisit[child])
        {
            ans = true;
        }
        if (!vis[child])
        {
            dfs(child);
        }
    }
    // kaj sesh
    pathVisit[parent] = false;
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        // adj[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(pathVisit, false, sizeof(pathVisit));
    ans = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    if (ans)
        cout << "Cycle detected";
    else
        cout << "Cycle not detected";
    return 0;
}