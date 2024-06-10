#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
vector<pair<long long int, long long int>> v[N];

long long int dis[N];

class cmp
{
public:
    bool operator()(pair<long long int, long long int> a, pair<long long int, long long int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(long long int src)
{
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, cmp> pq;

    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<long long int, long long int> parent = pq.top();
        pq.pop();

        long long int node = parent.first;
        long long int cost = parent.second;

        for (pair<long long int, long long int> child : v[node])
        {
            long long int childNode = child.first;
            long long int childCost = child.second;
            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}

int main()
{

    long long int n, e;
    cin >> n >> e;

    while (e--)
    {
        long long int a, b, c;

        cin >> a >> b >> c;

        v[a].push_back({b, c});
    }

    for (long long int i = 1; i <= n; i++)
    {
        dis[i] = 1e18;
    }

    long long int s, t, d, dw;

    cin >> s;
    dijkstra(s);

    cin >> t;
    while (t--)
    {
        cin >> d >> dw;
        if (dis[d] <= dw)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}