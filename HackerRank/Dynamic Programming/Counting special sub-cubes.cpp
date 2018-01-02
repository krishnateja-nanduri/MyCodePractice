//https://www.hackerrank.com/challenges/counting-special-sub-cubes/problem

#include <bits/stdc++.h>
#define MI(x,y) ((x)<(y)?(x):(y))
#define MA(x,y) ((x)>(y)?(x):(y))
using namespace std;
const int N=55;
int a[N][N][N][2],n;
int input(){
    memset(a,0,sizeof(a));
    cin >> n;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    for (int k=1;k<=n;k++)
    cin >> a[i][j][k][0];
    return 0;
}

int sol(){
    int num=0;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    for (int k=1;k<=n;k++)
    num+=(a[i][j][k][0]==1);
    cout << num;

    for (int s=1,t=1;s<n;s++,t^=1){
        num=0;
        for (int i=1;i<=n-s;i++)
        for (int j=1;j<=n-s;j++)
        for (int k=1;k<=n-s;k++){
            a[i][j][k][t]=  MA(MA(MA(a[i][j][k][!t],a[i][j][k+1][!t]),
                            MA(a[i][j+1][k][!t],a[i][j+1][k+1][!t])),
                            MA(MA(a[i+1][j][k][!t],a[i+1][j][k+1][!t]),
                            MA(a[i+1][j+1][k][!t],a[i+1][j+1][k+1][!t])));
            num+=(a[i][j][k][t]==s+1);
        }
        cout<<"\t"<< num ;
    }
    cout << endl;

    return 0;
}

int main() {
    int test;
    cin >> test;
    while (test--){
        input();
        sol();
    }
    return 0;
}
