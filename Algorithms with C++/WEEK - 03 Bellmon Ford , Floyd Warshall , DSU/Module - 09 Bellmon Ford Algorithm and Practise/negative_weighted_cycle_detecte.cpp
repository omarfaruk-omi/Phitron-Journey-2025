#include <bits/stdc++.h>
using namespace std;

int dist[105];
int n, e;
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
vector<edge> edge_list;
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

    //for chacking cycle present or not
    bool cycle = false;
    for (auto ed : edge_list)
    {
        int a = ed.a;
        int b = ed.b;
        int c = ed.c;

        if (dist[a] != INT_MAX && dist[a] + c < dist[b])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
        cout << "Negative weighted cycle detected\n";
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << "->" << dist[i] << endl;
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
    // for (auto ed : edge_list)
    // {
    //     cout << ed.a << " " << ed.b << " " << ed.c << endl;
    // }
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    bellmon_ford();

    return 0;
}