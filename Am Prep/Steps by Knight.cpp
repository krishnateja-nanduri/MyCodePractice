//https://practice.geeksforgeeks.org/problems/steps-by-knight/0 
//*****

#include<bits/stdc++.h>
#include <iostream>
using namespace std;
struct cell
{
    int x,y;
    int dis;
    cell(){}
    cell(int x,int y,int dis): x(x),y(y),dis(dis){}
};
bool valid(int x,int y,int n)
{
    if(x>=1 && x<=n && y>=1 && y<=n)
       return 1;
    return 0;
}
int knightsteps(int s[],int t[],int n)
{
    queue<cell>q;
    bool visited[n+1][n+1];
    int posx[]={-1,-2,1,2,-2,-1,1,2};
    int posy[]={-2,-1,-2,-1,1,2,2,1};
    q.push(cell(s[0],s[1],0));
    cell p;
    int x;
    int y;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            visited[i][j]=0;
        }
    }
    visited[s[0]][s[1]]=1;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        visited[p.x][p.y]=1;
        if(p.x==t[0]&&p.y==t[1])
        return p.dis;
        for(int i=0;i<8;i++)
        {
            x=p.x+posx[i];
            y=p.y+posy[i];
            if(valid(x,y,n)&&(!visited[x][y]))
            q.push(cell(x,y,(p.dis)+1));
            
        }
    }
    
    
}
int main() {
	int t;
	cin >> t;
	while(t--)
	{
	   int n;
	   cin >> n;
	   int s[2];
	   cin >> s[0] >> s[1];
	   int t[2];
	   cin >> t[0] >> t[1];
	   cout << knightsteps(s,t,n);
	   cout << endl;
	}
	return 0;
}
