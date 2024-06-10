#include <bits/stdc++.h>

using namespace std;

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const int N = 1e5 + 5;
int dis[N];

int main()
{

    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
        // EdgeList.push_back(Edge(v, u, c));
    }

    for (int i = 0; i <= n - 1; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[0] = 0;
    // Time complexity O(V*E)
    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;

            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    bool cycle = false;
    for (Edge ed : EdgeList)
    {
        int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;

        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
            // dis[v] = dis[u] + c;
        }
    }

    if (cycle)
    {
        cout << "Cycle found. No answer." << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " -> " << dis[i] << endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }

    // for (Edge ed : EdgeList)
    // {
    //     cout << ed.u << " " << ed.v << " " << ed.c << endl;
    // }

    return 0;
}
// Test case 1
//  4 4
//  0 2 5
//  0 3 12
//  2 1 2
//  1 3 3

// Test case 2
// 4 4
// 1 3 -3
// 0 3 5
// 2 1 1
// 0 2 -2