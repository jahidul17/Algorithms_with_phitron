#include <bits/stdc++.h>

using namespace std;
const int N = 100;
vector<pair<int, int>> v[N];

int dis[N];
// Time complexity O(V*E) here(E=n-1)

class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src)
{
    // queue<pair<int, int>> q;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();

        int node = parent.first;
        int cost = parent.second;

        for (pair<int, int> child : v[node])
        {
            int childNode = child.first;
            int childCost = child.second;
            if (cost + childCost < dis[childNode])
            {
                // Path relax
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
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
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    // memset(dis, INT_MAX, sizeof(dis)); //haven't work
    // INT_MAX=infinity value or height value

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(0);

    // For Test
    //  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    // pq.push({1, 10});
    // pq.push({3, 7});
    // pq.push({2, 15});
    // pq.push({4, 5});

    // while (!pq.empty())
    // {
    //     cout << pq.top().first << " " << pq.top().second << endl;
    //     pq.pop();
    // }

    for (int i = 0; i < n; i++)
    {
        cout << i << "->" << dis[i] << endl;
    }

    return 0;
}