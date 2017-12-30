//https://www.hackerrank.com/challenges/taras-beautiful-permutations/problem

#include <bits/stdc++.h>  
using namespace std ;

#define fr(i, a, b) for(i=a; i<=b; i++)
#define fb(i, a, b) for(i=a; i>=b; i--)

const int mod = 1e9 + 7;
const int maxn = 2 * 1e3 + 5;

int F[ maxn ], dp[ maxn ][ maxn ], inv[ maxn ];

int power(int a, int b, int m = mod) {
    int res = 1;
    while( b ) {
        if( b & 1 ) {
            res = 1LL * res * a % m;
        }
        a = 1LL * a * a % m;
        b /= 2;
    }
    return res;
}

void pre() {
    int i, j;
    dp[0][0] = F[0] = inv[0] = 1;
    fr(i, 1, 2000) {
        F[i] = 1LL * F[i-1] * i % mod;
        dp[i][0] = F[i];
        inv[i] = power(F[i], mod-2) % mod;
    }

    fr(i, 0, 2000) {
        int s1 = 0, s2 = 0;
        fr(j, 1, 2000) {
            if(i-1 >= 0) dp[i][j] = 1LL * i * dp[i-1][j] % mod;
            dp[i][j] += 1LL * j * dp[i][j-1] * (i + 2 * (j-1)) % mod;
            if( dp[i][j] >= mod ) dp[i][j] -= mod;
            dp[i][j] += 1LL * ( s1 + s2 ) * F[j] % mod;
            if( dp[i][j] >= mod ) dp[i][j] -= mod;
            int x = 1LL * dp[i][j-1] * inv[j-1] % mod;
            s1 += 1LL * i * x % mod; 
            if( s1 >= mod ) s1 -= mod;
            s2 += 1LL * x * (2 * j - 1) % mod;
            if( s2 >= mod ) s2 -= mod;
        }
    }
}

int main() {
    pre();
    int t; cin >> t;
    int sm = 0;
    while( t-- ) {
        map<int, int> M;
        int n, m1 = 0, m2 = 0; cin >> n;
        sm += n;
        int i; fr(i, 1, n) {
            int x; cin >> x;
            M[x] ++;
            if( M[x] == 2 ) {
                m2 ++; m1 --;
            } else {
                m1 ++;
            }
        }
        cout << dp[m1][m2] << "\n";
    }
    return 0;
}
