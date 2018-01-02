//https://www.hackerrank.com/challenges/black-n-white-tree-1/problem

#include <bits/stdc++.h>
using namespace std;
const int N=200002;
int w[2],w2[2];
vector <int> v[N];
vector <pair <int,int> > v2[N];
int a[N],d[N],fr[N];
bool f[N];

void dfs(int x,int y){
    f[x]=1;
    w[y]++;
    w2[y]=x;
    for (int i=0;i<v[x].size();i++)
    if (!f[v[x][i]])
        dfs(v[x][i],(y^1));
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0,x,y;i<m;i++){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int k=0;
    for (int i=1;i<=n;i++)
    if (!f[i]){
        w[0]=w[1]=0;
        dfs(i,0);
        k+=abs(w[0]-w[1]);
        a[abs(w[0]-w[1])]++;
        if (w[0]<w[1]) swap(w2[0],w2[1]);
        v2[abs(w[0]-w[1])].push_back({w2[0],w2[1]});
    }

    for (int j=1;j<=k;j++) d[j]=N,fr[j]=-1;

    for (int i=1;i<=n;i++)
    if (a[i]){
        for (int j=0;j+i<=k;j++)
        if (d[i+j]>d[j]+1)
            d[i+j]=d[j]+1,
            fr[i+j]=j;

        for (int j=1;j<=k;j++)
        if (d[j]>a[i]) 
            d[j]=N;
        else 
            d[j]=0;
    }

    int ans=k;
    int kk=k;
    for (int i=0;i<=k;i++)
    if(d[i]<N) 
        if (ans>abs(k-i*2))
            ans=abs(k-i*2),
            kk=i;

    if (kk==0) kk=k;

    vector <pair <int,int> > ap;

    vector <int> BL,WH;
    int sz=kk;

    while (kk){
        sz=kk-fr[kk];
        kk=fr[kk];
        BL.push_back(v2[sz].back().first);
        v2[sz].pop_back();
    }

    for (int i=0;i<=k;i++)
       while (v2[i].size()){
        WH.push_back(v2[i].back().first);
        v2[i].pop_back();
    }

    if (BL.size() && WH.size()){
        for (int i=0;i<BL.size();i++)
            ap.push_back({BL[i],WH[0]});
        for (int i=0;i<WH.size();i++)
            ap.push_back({BL[0],WH[i]});
    }

    cout<<ans<<" "<<ap.size()<<endl;
    for (int i=0;i<ap.size();i++)
        printf("%d %d\n",ap[i].first,ap[i].second);
    return 0;
}
