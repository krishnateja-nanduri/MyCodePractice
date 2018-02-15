//https://practice.geeksforgeeks.org/problems/knight-walk/0

#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int dx[8]={-1,1,-1,1,2,-2,2,-2};
int dy[8]={2,2,-2,-2,1,1,-1,-1};
int dist[100][100];
int main() {
    int t,n,i,j,k,m,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)dist[i][j]=-1;
        int s1,s2,d1,d2;
        cin>>s1>>s2>>d1>>d2;
        queue<pair<int,int> >q;
        
        q.push({s1,s2});
        dist[s1][s2]=0;
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            if(p.fi==d1&&p.se==d2)
            break;
            for(i=0;i<8;i++)
            {
                x=p.fi+dx[i];
                y=p.se+dy[i];
                if(x<1||y<1||x>n||y>m||dist[x][y]>-1)
                continue;
                dist[x][y]=dist[p.fi][p.se]+1;
                q.push(make_pair(x,y));
            }
            
        }
        cout<<dist[d1][d2]<<"\n";
    }
	//code
	return 0;
}

