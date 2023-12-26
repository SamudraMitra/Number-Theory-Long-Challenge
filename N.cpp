// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef long double ld;
// #define fastio                        \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL)
// #define max3(a, b, c) max(max(a, b), c)
// #define max4(a, b, c, d) max(max(a, b), max(c, d))
// #define fr(i, n) for (ll i = 0; i < n; i++)
// ll gcd(ll a, ll b)
// {
//     return b == 0 ? a : gcd(b, a % b);
// }
// long long binpow(long long a, long long b, long long m = 1000000007)
// {
//     a %= m;
//     long long res = 1;
//     while (b > 0)
//     {
//         if (b & 1)
//             res = res * a % m;
//         a = a * a % m;
//         b >>= 1;
//     }
//     return res;
// }
// int main()
// {
//     fastio;
//     ll mod = 1e9 + 7;
//     ll N = (ll)1e5;
//     vector<ll> spf(N + 1);
//     for (ll i = 1; i <= N; i++)
//         spf[i] = i;
//     for (ll i = 2; i <= N; i++)
//     {
//         if (spf[i] == i)
//         {
//             for (ll j = i * i; j <= N; j += i)
//             {
//                 if (spf[j] == j)
//                     spf[j] = i;
//             }
//         }
//     }
//     vector<ll> mob(N + 1, 0);
//     mob[1] = 1;
//     for (ll x = 1; x <= N; x++)
//     {
//         for (ll y = 2 * x; y <= N; y += x)
//         {
//             mob[y] -= mob[x];
//         }
//     }
//     ll res = 0;
//     ll n;
//     cin >> n;
//     vector<ll> v(n);
//     for (auto &i : v)
//         cin >> i;
//     vector<ll> fact(N + 1, 0);
//     for (ll i = 0; i < n; i++)
//     {
//         ll x = v[i];
//         for (ll i = 1; i * i <= x; i++)
//         {
//             if ((x % i) == 0)
//             {
//                 fact[i]++;
//                 if (i != (x / i))
//                     fact[x / i]++;
//             }
//         }
//     }
//     for (ll i = 1; i <= N; i++)
//     {
//         res += (((((binpow(2, fact[i]) - 1 + mod) % mod) * mob[i]) % mod) + mod) % mod;
//         res %= mod;
//     }
//     cout << res << "\n";
// }

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
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
long long binpow(long long a, long long b, long long m = mod)
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

int main()
{
    fastio;
    ll N = 1e6;
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> freq;
    for (auto &i : v)
    {
        cin >> i;
        freq[i]++;
    }
    vector<ll> cnt(N + 1, 0);
    vector<ll> f(N + 1, 0);
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = i; j <= N; j += i)
        {
            if (freq.find(j) != freq.end())
            {
                cnt[i] += freq[j];
            }
        }
    }
    for (ll i = 1; i <= N; i++)
    {
        f[i] = (binpow(2, cnt[i]) - 1 + mod) % mod;
    }
    vector<ll> g(N + 1, 0);
    for (ll i = N; i >= 1; i--)
    {
        ll res = 0;
        for (ll j = 2 * i; j <= N; j += i)
        {
            res += g[j];
            res %= mod;
        }
        g[i] = ((((f[i] - res) % mod) + mod) % mod);
    }
    cout << g[1] << "\n";
}