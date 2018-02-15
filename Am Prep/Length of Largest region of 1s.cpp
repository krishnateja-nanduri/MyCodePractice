//https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s/0

#include<bits/stdc++.h>
#define MAX 50
using namespace std;
bool isValid(int i, int j, int N, int M){
    return (i>=0&&i<N&&j>=0&&j<M);
}
void dfs(int A[][MAX],int N, int M, int i, int j, int vis[][MAX], int row[], int col[],int &o){
    vis[i][j]=1;o++;
    for(int k=0;k<8;k++){
        if(isValid(i+row[k],j+col[k],N,M)&&A[i+row[k]][j+col[k]]==1&&!vis[i+row[k]][j+col[k]])dfs(A,N,M,i+row[k],j+col[k],vis,row,col,o);
    }
}
int findIslands(int A[MAX][MAX], int N, int M)
{
    int row[]={0,1,0,-1,1,-1,-1,1};
    int col[]={1,0,-1,0,1,-1,1,-1};
    int vis[MAX][MAX];
    memset(vis,0,sizeof(vis));
    int count=0;
    for(int i=0;i<N;i++)
      for(int j=0;j<M;j++)
       if(A[i][j]==1&&!vis[i][j]){int o=0;dfs(A,N,M,i,j,vis,row,col,o);count=max(count,o);}
    return count;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int A[MAX][MAX];
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)cin>>A[i][j];
        cout<<findIslands(A,n,m)<<"\n";
    }
    return 0;
}
