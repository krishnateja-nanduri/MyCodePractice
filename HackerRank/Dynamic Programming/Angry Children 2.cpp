//https://www.hackerrank.com/challenges/angry-children-2/problem

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int maxn = 100005;
LL c[maxn];
LL sum[maxn];
LL n, k;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	sort(c + 1, c + n + 1);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + c[i];
	}
	LL temp = 0;
	for (int i = 1; i <= k; i++) {
		temp += (i - 1) * c[i];
		temp -= (k - i) * c[i];
	}
	LL res = temp;
	int l = 2, r = k + 1;
	for (; r <= n; l++, r++) {
		temp += (k - 1) * c[r] - (sum[r - 1] - sum[l - 1]);
		temp -= (sum[r - 1] - sum[l - 1]) - (k - 1) * c[l - 1];
		res = min(res, temp);
	}
	cout << res << endl;
}
