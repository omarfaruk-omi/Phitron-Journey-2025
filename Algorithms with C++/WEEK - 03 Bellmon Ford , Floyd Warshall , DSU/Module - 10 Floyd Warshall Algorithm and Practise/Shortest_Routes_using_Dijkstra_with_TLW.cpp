#include <bits/stdc++.h>
using namespace std;
void dijkstra(int sec)
{

}
int main()
{
    int v,e,q;
    cin >> v >> e >> q;
    vector<vector<pair<int,int>>> adj_list(v+1);
    while (e--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});

    }
   
    while(q--)
    {
        int s,d;
        cin >> s >> d;
        vector <int> dist(v+1,INT_MAX);
        //dijkstra
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,s});
        dist[s]=0;
        while(!pq.empty())
        {
            pair<int,int> par = pq.top();
            pq.pop();
            int par_node = par.second;
            int par_dist = par.first;

            for(auto cd : adj_list[par_node])
            {
                int cd_node = cd.first;
                int cd_dist = cd.second;
                if(par_dist+cd_dist < dist[cd_node])
                {
                    dist[cd_node]=par_dist+cd_dist;
                    pq.push({dist[cd_node],cd_node});
                }
            }
        }

        if(dist[d]==INT_MAX)
            cout<<"-1"<<endl;
        else
            cout<<dist[d]<<endl;

    }
    return 0;
}