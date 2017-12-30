//https://www.hackerrank.com/challenges/mr-k-marsh

#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
char mat[maxn][maxn];
int n, m;
int sum[maxn][maxn];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> (mat[i] + 1);
		sum[i][0] = 0;
		for (int j = 1; j <= m; j++) {
			sum[i][j] = sum[i][j - 1] + (mat[i][j] == 'x');
		}
	}

	int res = 0;
	for (int i = 1; i <= m; i++) for (int j = i + 1; j <= m; j++) {
		int p = -1;
		for (int k = 1; k <= n; k++) {
			if (sum[k][j] - sum[k][i - 1] == 0) {
				if (p > 0) {
					res = max(res, 2 * (j - i + k - p));
				} else if (p == -1) p = k;
			} else if (mat[k][i] == 'x' || mat[k][j] == 'x') {
				p = -1;
			}
		}
	}
	if (res > 0)
		cout << res;
	else {
		cout << "impossible";
	}
	return 0;
}