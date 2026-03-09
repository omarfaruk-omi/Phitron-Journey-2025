#include <bits/stdc++.h>
using namespace std;

long long int dist[1005];
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
    for (int i = 1; i < n; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;

            if (dist[a] != LLONG_MAX && dist[a] + c < dist[b])
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

        if (dist[a] != LLONG_MAX && dist[a] + c < dist[b])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
        cout << "Negative Cycle Detected\n";
    else
    {
        int t;
        cin >> t;
        while(t--)
        {
            int d;
            cin >> d;
            if(dist[d] == LLONG_MAX)
                cout << "Not Possible\n";
            else
                cout << dist[d] << endl;
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
       
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = LLONG_MAX;
    }
    int src;
    cin >> src;
    dist[src] = 0;
    bellmon_ford();

    return 0;
}