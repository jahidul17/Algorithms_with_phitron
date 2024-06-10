#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5; // 100000+5
vector<int> v[N];
bool vis[N];
int childNode = 1;
void dfs(int src)
{
    // cout << src << endl;
    vis[src] = true;

    for (int i = 0; i < v[src].size(); i++)
    {
        int child = v[src][i];
        if (vis[child] == false)
        {
            dfs(child);
            childNode++;
        }
    }
}

vector<int> c_node;

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

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            dfs(i);
            count++;
            // cout << "Child Node- " << childNode << endl;
            c_node.push_back(childNode);
            // cout << "Component- " << count << endl;
            childNode = 1;
        }
    }
    // cout << "Final Component- " << count << endl;

    sort(c_node.begin(), c_node.end());
    for (auto val : c_node)
    {
        cout << val << " ";
    }

    return 0;
}
