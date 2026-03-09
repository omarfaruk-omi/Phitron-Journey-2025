#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++)
        {
            int c;
            cin >> c;
            pq.push({c,i});
        }
        vector<int> ans;
        for(int i=0;i<2;i++)
        {
            pair<int,int> cd = pq.top();
            int l =cd.second;
            //int r =cd.first;
            //cout << l << " ";
            ans.push_back(l);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        cout << ans.front() <<" " << ans.back() << endl;
        // cout << endl;

    }
    return 0;
}