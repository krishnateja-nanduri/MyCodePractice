//https://www.hackerrank.com/challenges/wet-shark-and-two-subsequences/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_SIZE 128
#define MAX_SUM 2048
#define MOD 1000000007

long long a[MAX_SIZE];
int m, r, s;
long long f[MAX_SIZE][MAX_SUM];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int sa, sb;
    long long res = 0;

    cin >> m >> r >> s;
    sa = (r + s) / 2;
    sb = (r - s) / 2;
    for (int i = 0; i < m; i++)
        cin >> a[i];

    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = m; j >= 1; j--) {
            for (int k = 2000; k >= 0; k--) {
                if (k >= a[i])
                    f[j][k] = (f[j][k] + f[j - 1][k - a[i]]) % MOD;
            }
        }
    }

    for (int i = 1; i <= m; i++)
        res = (res + (f[i][sa] * f[i][sb]) % MOD) % MOD;
    
    cout << res << endl;
    return 0;
}
