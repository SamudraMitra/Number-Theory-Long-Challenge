#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll modinv(ll a, ll p)
{
    return binpow(a, p - 2, p);
}
int main()
{
    fastio;
    ll a, b, p, x;
    cin >> a >> b >> p >> x;
    if ((a % p) == 0)
    {
        cout << 0 << "\n";
    }
    ll res = 0;
    for (ll i = 0; i < p - 1; i++)
    {
        ll modd = p * (p - 1);
        ll z = binpow(a, i, p); // x
        ll M = (b * modinv(z, p)) % p;
        ll n = (((p * i) % modd) + ((((((p - 1) * (p - 1)) % modd) * M) % modd)) % modd) % modd;
        if (n <= x)
        {
            res += ((x - n) / modd) + 1;
        }
        // res += ((x - n) / modd) + 1;
        // ll complete_cycles = (x / modd);

        // res += complete_cycles;
        // ll remain = x % modd;
        // if (remain >= n)
        //     res++;
    }
    cout << res << "\n";
}