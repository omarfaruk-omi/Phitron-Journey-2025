#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e; //input node and edge
    cin >> n >> e;
    int adj_mat[n][n]; //create a adj matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;  // set digonal valur as 0
            else
                adj_mat[i][j] = INT_MAX;    //set all the value firstly int max
        }
    }
    while (e--)
    {
        int a, b, c; // input nodes and weighted
        cin >> a >> b >> c;
        adj_mat[a][b] = c; // initialise value in the matrix row to coloum as node conection
        // adj_mat[b][a]=c; for undirected
    }

    for (int k = 0; k < n; k++) // its outward use
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) 
            {
                if (adj_mat[i][k] != INT_MAX  && adj_mat[k][j] != INT_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j]; // chacking dist of (i -> k + k -> j)   distance is less than  i -> j __ then we reaplace it
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(adj_mat[i][j]==INT_MAX)
                cout << "INF ";
            else
                cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}