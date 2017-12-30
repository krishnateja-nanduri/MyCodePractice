//https://www.hackerrank.com/challenges/choosing-white-balls/problem

#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef unsigned long long ull;

const int SMALL = 25;

struct Map {
    double small[(1 << SMALL) + 5];
    map<ull, double> big[100];

    Map() {
        forn (i, 1 << SMALL)
            small[i] = -1;
    }

    double &get(int len, ull mask) {
        if (len < SMALL - 1)
            return small[mask | (ull(1) << len)];
        return big[len][mask];
    }

    bool has(int len, ull mask) {
        if (len < SMALL - 1)
            return small[mask | (ull(1) << len)] >= 0;
        return big[len].count(mask);
    }
} d;

int k;

ull del(ull mask, int k) {
    ull low1 = (1ll << k) - 1;
    ull low = mask & low1;
    ull high = (mask >> 1) & ~low1;
    return low | high;
}

int kth(ull mask, int k) {
    return (mask >> k) & 1ll;
}

double calc(ull mask, int len) {
    if (len == k)
        return 0;
    if (d.has(len, mask))
        return d.get(len, mask);
    double &res = d.get(len, mask);
    res = 0;
    if (res)
        return res;
    forn (i, len) {
        int j = len - i - 1;

        res += (1. / len) *
            max(calc(del(mask, i), len - 1) + kth(mask, i),
                calc(del(mask, j), len - 1) + kth(mask, j));
    }
    return res;
}

int main() {
    #ifdef LOCAL
    assert(freopen("choosing-the-right-ball.in", "r", stdin));
    #else
    #endif
    int n;
    string s;
    cin >> n >> k >> s;
    k = n - k;
    ull mask = 0;
    forn (i, n)
        mask |= ull(s[i] == 'W') << i;
    cout.precision(10);
    cout << fixed;
    cout << calc(mask, n) << '\n';
}
