//https://www.hackerrank.com/challenges/alien-languages/problem

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int MAX_LEN = 500005;
const int MAXN = 100005;
const LL MOD = 100000007;
int n, m;
LL dp[MAX_LEN], f[20][MAXN], g[20];

int main(int argc, char const *argv[])
{
	int Test;
	cin >> Test;
	while (Test--) {
		cin >> n >> m;
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		memset(dp, 0, sizeof(dp));
		int mid = n >> 1;
		for (int i = 0; i <= mid; i++)
			f[0][i] = 1;

		int len = 0;
		for (int i = 1, p = 1; i <= m && p <= mid; i++, p <<= 1) {
			for (int j = p; j <= mid; j++) {
				f[i][j] = (f[i][j - 1] + f[i - 1][j >> 1]) % MOD;
			}
			len = i;
		}

		for (int i = 1; i <= len + 1; i++) {
			for (int j = mid + 1; j <= n; j++) {
				g[i] = (g[i] + f[i - 1][j >> 1]) % MOD;
			}
		}

		dp[0] = 1;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= len + 1; j++) {
				if (i - j < 0) continue;
				dp[i] += dp[i - j] * g[j];
				dp[i] %= MOD;
			}
		}

		cout << dp[m] << endl;
	}
	return 0;
}
