//https://www.hackerrank.com/challenges/gcd-matrix/problem

#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1e5+1;

long long _a[maxn], _b[maxn], a[maxn], b[maxn], c[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, m, q;
	cin >> n >> m >> q;

	for(long long i = 0; i < n; i++)
		cin >> _a[i];

	for(long long i = 0; i < m; i++)
		cin >> _b[i];

	while(q--){
		memset(c, 0, sizeof(c));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		long long x, y, _x, _y;
		cin >> x >> y >> _x >> _y;
		for(long long i = x; i <= _x; i++)
			a[_a[i]]++;
		for(long long i = y; i <= _y; i++)
			b[_b[i]]++;
		long long ans = 0;
		for(long long g = maxn-1; g >= 1; g--){
			long long cnt_a = 0, cnt_b = 0;
			for(long long i = g; i < maxn; i += g)
				cnt_a += a[i], cnt_b += b[i];
			c[g] = cnt_a*cnt_b;
			for(long long i = 2*g; i < maxn; i += g)
				c[g] -= c[i];
			if(c[g]) ans++;
		}
		cout << ans << "\n";
	}

	return 0;
}
