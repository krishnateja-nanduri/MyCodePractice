//https://www.hackerrank.com/challenges/queens-on-board/problem

#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define pb push_back

int ri()
{
  int x;
  cin >> x;
  return x;
}

const int N = 50, M = 5, MM = 1 << M, MOD = 1000000007;
char a[N][M+1];
int dp[2][MM][MM][MM];

int main()
{
  for (int cc = ri(); cc--; ) {
    int n = ri(), m = ri(), mm = 1 << m;
    vector<vector<int>> tr(mm);
    REP(i, n)
      cin >> a[i];
    for (int obs = mm-1; ; obs = obs-1 & mm-1) {
      int ava = mm-1-obs;
      for (int h = ava; ; h = h-1 & ava) {
        bool f = false, bad = false;
        REP(i, m)
          if (obs & 1 << i)
            f = false;
          else if (h & 1 << i) {
            if (f) {
              bad = true;
              break;
            }
            f = true;
          }
        if (! bad)
          tr[obs].pb(h);
        if (! h) break;
      }
      if (! obs) break;
    }
    memset(dp, 0, sizeof dp);
    dp[0][0][0][0] = 1;
    REP(i, n) {
      memset(dp[i+1&1], 0, sizeof dp[0]);
      int obs = 0;
      REP(j, m)
        if (a[i][j] == '#')
          obs |= 1 << j;
      REP(j, mm)
        REP(k, mm)
          REP(l, mm)
            if (dp[i&1][j][k][l])
              for (int h: tr[obs])
                if (! (h & (j|k|l))) {
                  int jj = j & ~obs | h,
                    kk = (k & ~obs | h) >> 1,
                    ll = (l & ~obs | h) << 1 & mm-1;
                  (dp[i+1&1][jj][kk][ll] += dp[i&1][j][k][l]) %= MOD;
                }
    }
    int ans = -1;
    REP(j, mm)
      REP(k, mm)
        REP(l, mm)
          (ans += dp[n&1][j][k][l]) %= MOD;
    cout << ans <<endl;
  }
}
