//https://www.hackerrank.com/challenges/counting-road-networks/problem

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define forn(i, n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define sz(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()

const int mod = 663224321;
void add (int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
void sub (int &a, int b)
{
    a -= b;
    if (a < 0)
        a += mod;
}
int mult (int a, int b)
{
    return (ll)a * b % mod;
}
int powmod (int a, ll pw)
{
    int res = 1;
    while (pw)
    {
        if (pw & 1)
            res = mult(res, a);
        a = mult(a, a);
        pw >>= 1;
    }
    return res;
}

const int N = (int)1e5 + 10;
int fact[N], ifact[N], inv[N], ans[N];
bool calc = false;

int inverse (int a)
{
    assert(0 < a && a < mod);
    return powmod(a, mod - 2);
}

typedef long double T;

struct cd {
    T re, im;

    cd(): re(0), im(0) {}

    cd(T _re): re(_re), im(0) {}

    cd(T _re, T _im): re(_re), im(_im) {}

    cd operator + (const cd &o) const
    {
        return cd(re + o.re, im + o.im);
    }

    cd operator - (const cd &o) const
    {
        return cd(re - o.re, im - o.im);
    }

    cd operator * (const cd &o) const
    {
        return cd(re * o.re - im * o.im, re * o.im + im * o.re);
    }

    cd operator / (double c) const
    {
        return cd(re / c, im / c);
    }

    T real ()
    {
        return re;
    }
};

cd wp[1 << 19];
const T pi = acos(-1);
void fft (vector<cd> &a, bool isinv)
{
    const int n = sz(a);
    for(int i = 1, j = 0; i < n; i++)
    {
        int bit = (n >> 1);
        while (j & bit)
        {
            j ^= bit;
            bit >>= 1;
        }
        j ^= bit;
        if(i < j)
            swap(a[i], a[j]);
    }

    for(int k = 1; k < n; k <<= 1)
    {
        wp[0] = cd(1);
        wp[1] = cd(cos(pi / k), sin(pi / k));

        for(int i = 2; i < k; i++)
            wp[i] = wp[i >> 1] * wp[(i + 1) >> 1];

        for(int i = 0; i < n; i += 2 * k)
        forn (j, k)
        {
            cd v = a[i + j], u = a[i + j + k] * wp[j];
            a[i + j] = v + u;
            a[i + j + k] = v - u;
        }
    }

    if (isinv)
    {
        for(int i = 0; i < n; i++)
            a[i] = a[i] / (T)n;
        reverse(a.begin() + 1, a.end());
    }
}

vi sum (const vi &l, const vi &r)
{
    vi rans(max(sz(l), sz(r)));
    forn (i, sz(l))
        add(rans[i], l[i]);
    forn (i, sz(r))
        add(rans[i], r[i]);
    return rans;
}

vi brutmult (const vi &l, const vi &r)
{
    vi rans(sz(l) + sz(r) - 1);
    forn (i, sz(l)) forn (j, sz(r))
        add(rans[i + j], mult(l[i], r[j]));
    return rans;
}

vi fftmult (const vi &l, const vi &r)
{
    const int bnd = max(sz(l), sz(r));
    int len = 1;
    while (len < bnd)
        len *= 2;

    vector<cd> fl(2 * len), fr(2 * len);
    copy(ALL(l), fl.begin());
    copy(ALL(r), fr.begin());
    fft(fl, false);
    fft(fr, false);
    forn (i, sz(fl))
        fl[i] = fl[i] * fr[i];

    fft(fl, true);
    vi res(sz(fl));
    forn (i, sz(fl))
    {
        ll x = (ll)round(fl[i].real());
        res[i] = x % mod;
        if (res[i] < 0)
            res[i] += mod;
    }

    while (!res.empty() && res.back() == 0)
        res.pop_back();
    return res;
}

vi mult (const vi &l, const vi &r)
{
    const int base = (int)sqrt(mod);
    vi res(sz(l) + sz(r) - 1);

    forn (tl, 2) forn (tr, 2)
    {
        vi cl(sz(l)), cr(sz(r));

        int resmult = mult((tl ? base : 1), (tr ? base : 1));
        forn (i, sz(l))
            cl[i] = (tl ? l[i] / base : l[i] % base);
        forn (i, sz(r))
            cr[i] = (tr ? r[i] / base : r[i] % base);

        vi curres = fftmult(cl, cr);
        curres.resize(sz(res));
        forn (i, sz(res))
            add(res[i], mult(curres[i], resmult));
    }

    return res;
}

vi rec (const vi &w, int len)
{
    if (len == 1)
    {
        assert(w[0] != 0);
        return {inverse(w[0])};
    }

    vi C = rec(w, len / 2);
    vi A(w.begin(), w.begin() + len / 2);
    vi AC = mult(A, C);

    AC.resize(len);
    AC = vi (AC.begin() + len / 2, AC.end());

    vi B(w.begin() + len / 2, w.begin() + len);
    vi BC = mult(B, C);
    BC.resize(len / 2);

    vi D = mult(C, sum(BC, AC));
    D.resize(len / 2);
    forn (i, sz(D))
    {
        int x = 0;
        sub(x, D[i]);
        D[i] = x;
    }

    vi res(len);
    copy(C.begin(), C.begin() + len / 2, res.begin());
    copy(D.begin(), D.begin() + len / 2, res.begin() + len / 2);

    return res;
}

vi invseries (vi w)
{
    int len = 1;
    while (len <= N)
        len *= 2;
    w.resize(len);

    return rec(w, len);
}

void precalc ()
{
    calc = true;
    fact[0] = fact[1] = inv[1] = ifact[0] = ifact[1] = 1;

    for (int i = 2; i < N; i++)
    {
        inv[i] = mod - mult (mod / i, inv[mod % i]);
        assert(mult(i, inv[i]) == 1);
        fact[i] = mult(fact[i - 1], i);
        ifact[i] = mult(ifact[i - 1], inv[i]);
    }

    vi a(N), b(N, 1);
    forn (i, N) if (i != 0)
    {
        a[i] = powmod(2, (ll)i * (i - 1) / 2LL);
        a[i] = mult(a[i], ifact[i - 1]);
        b[i] = mult(a[i], inv[i]);
    }

    vi res = mult(a, invseries(b));
    forn (i, N) if (i != 0)
        ans[i] = mult(res[i], fact[i - 1]);
}

void solve (int n)
{
    if (!calc)
        precalc();

    cout << ans[n] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    int n;
    while (cin >> n)
        solve(n);
}

