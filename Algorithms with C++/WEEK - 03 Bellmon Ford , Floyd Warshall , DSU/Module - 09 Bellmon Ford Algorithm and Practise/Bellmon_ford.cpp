#include <bits/stdc++.h>
using namespace std;
class edge
{
public:
    int a, b, c;
    edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int dist[105];
vector<edge> edge_list;
int n, e;

void bellmon_ford()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;

            if (dist[a] != INT_MAX && dist[a] + c < dist[b])
            {
                dist[b] = dist[a] + c;
            }
        }
    }
}
int main()
{

    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(edge(a, b, c));
        // edge_list.push_back(edge(b,a, c)); // only for undirected graph
    }
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    bellmon_ford();
    for (int i = 0; i < n; i++)
    {
        cout << i << "->" << dist[i] << endl;
    }
    return 0;
}