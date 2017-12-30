//https://www.hackerrank.com/challenges/cuttree/problem

//Didn't get the answer straight off. Editorial Basis.

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MM(a, b) memset(a,b,sizeof(a))
#define P(x) cout << #x << " = " << x << endl;
#define PP(a,n) for(int o=0;o<n;o++)cout<<#a<<"["<<o<<"] = "<<a[o]<<endl;
    
vector<int> g[55];
vector<int> tr[55];
LL dp[55][55][55][2];
bool used[55];
    
int n, maxCut;
    
void dfs(int u) {
    used[u] = 1;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(!used[v]) {
            tr[u].push_back(v);
            dfs(v);
        }
    }
}
    
LL f(int u, int nson, int cut, int choose) {
    if(cut < 0) return 0;
    if(nson == 0) return (cut == 0);
    LL &ret = dp[u][nson][cut][choose];
    if(ret != -1) return ret;
    ret = 0;
    if(choose == 0) {
        for(int i = 0; i < nson; i++) {
            int v = g[u][i];
            ret += f(v, g[v].size(), cut, 0);
            ret += f(v, g[v].size(), cut - 1, 1);
        }
        if(cut == 0) ret -= nson - 1;
    } else {
        int rson = g[u][nson - 1];
        ret += f(u, nson - 1, cut - 1, 1);
        for(int i = 0; i <= cut; i++) {
            ret += f(u, nson - 1, cut - i, 1) * f(rson, g[rson].size(), i, 1);
        }
    }
    return ret;
}
    
int main() {
    cin >> n >> maxCut;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    for(int i = 0; i < 55; i++) g[i] = tr[i];
    MM(dp, -1);
    LL ret = 0;
    for(int cut = 0; cut <= maxCut; cut++) {
        LL r1 = f(0, g[0].size(), cut, 0);
        LL r2 = f(0, g[0].size(), cut, 1);
        ret += r1 + r2;
    }
    cout << ret << endl;
    return 0;
}
