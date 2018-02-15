//https://practice.geeksforgeeks.org/problems/find-whether-path-exist/0

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,i,j,src,dest;
        cin>>n;
        int mat[n][n];
        vector<int> adj[n*n+10];
        bool vis[n*n+10];
        memset(vis,false,sizeof(vis));
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                cin>>mat[i][j];
                if (mat[i][j]==1)
                    src=(i*n)+j;
                if (mat[i][j]==2)
                    dest=(i*n)+j;
            }
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                int cur = (i*n)+j;
                int left = cur-1;
                int right = cur+1;
                int top = cur-n;
                int bottom = cur+n;
                if (mat[i][j]!=0)
                {
                    if (j>0 && mat[i][j-1]!=0)
                        adj[cur].push_back(left);
                    if (j<n-1 && mat[i][j+1]!=0)
                        adj[cur].push_back(right);
                    if (i>0 && mat[i-1][j]!=0)
                        adj[cur].push_back(top);
                    if (i<n-1 && mat[i+1][j]!=0)
                        adj[cur].push_back(bottom);
                }
            }
        }
        queue<int> q;
        q.push(src);
        while (!q.empty())
        {
            int e = q.front();
            vis[e]=true;
            q.pop();
            for (i=0;i<adj[e].size();i++)
            {
                int el = adj[e][i];
                if (!vis[el])
                {
                    q.push(el);
                }
            }
        }
        if (!vis[dest])
            cout<<"0";
        else
        {
            cout<<1;
        }
        cout<<"\n";
    }

    return 0;
}

