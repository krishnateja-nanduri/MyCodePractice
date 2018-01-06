//https://www.hackerrank.com/challenges/turn-off-the-lights/problem

#include <bits/stdc++.h>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 202100
#define SUM 23423
#define MAG 333
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,x,y,tot, flag,h,r,ans,koko,z,nl,nr,maxx,maxy,minx,miny;
ll a[100500], dp[100500], b[100500], used[100500];
string s;
ll Abs(ll x)
{
	return x>0?x:-x;
}
int main() {
	
	cin >> n >> k;
	for (i = 0; i < n; i++)
		cin >> a[i];
	ll ans = INF;
	for (i = 0; i <= k; i++)
		for (j = n-1-k; j <= n-1; j++)
		{
			if (j >= i && (j-i)%(2*k+1) == 0)
			{
				ll sum = 0;
				for (l = i; l <= j; l += 2*k+1)
					sum += a[l];
				ans = min(ans, sum);
			}
		}
	cout << ans << endl;
	
	return 0;
}
