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

const int N = 1e6 + 5;

int main()
{

    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    long long int dis[n + 1];

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e18;
    }

    int src;
    cin >> src;
    dis[src] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            long long int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;

            if (dis[u] < 1e18 && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    bool cycle = false;
    for (Edge ed : EdgeList)
    {
        long long int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;

        if (dis[u] < 1e18 && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }

    // Test Case
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;
        if (cycle == false)
        {
            if (dis[d] < 1e18)
            {
                cout << dis[d] << endl;
            }
            else
            {
                cout << "Not Possible" << endl;
            }
        }
    }

    return 0;
}