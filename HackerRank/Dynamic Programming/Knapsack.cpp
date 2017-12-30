//https://www.hackerrank.com/challenges/unbounded-knapsack/problem

#include <bits/stdc++.h>
using namespace std;

int dp[2001][2001];
int w[2001];
int main() {
    int tt,n,k;
    cin >> tt;
    while (tt--)
    {
        cin >> n  >> k;
        for (int i=1;i<=n;i++)
            cin >> w[i];
        for (int i=0;i<=2000;i++)
            dp[0][i] = dp[i][0] = 0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=k;j++)
                if (j >= w[i])
                    dp[i][j] = max(dp[i-1][j], dp[i][j-w[i]] + w[i]);
                else
                    dp[i][j] = dp[i-1][j];
        cout << dp[n][k]<<endl;
    }
    return 0;
}
