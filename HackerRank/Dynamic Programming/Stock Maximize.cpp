//https://www.hackerrank.com/challenges/stockmax/problem

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int maxn = 50005;
int n;
LL price[maxn];

int main() {
	int Test;
	cin >> Test;
	while (Test--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> price[i];
		price[0] = 100005;
		LL mx = price[n], res = 0, cnt = 0, sum = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (price[i] < mx) {
				cnt++;
				sum += price[i];
			} else {
				res += cnt * mx - sum;
				cnt = 0;
				sum = 0;
				mx = price[i];
			}
		}
		cout << res << endl;
	}
	return 0;
}
