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
ll nod(ll x)
{
    ll res = 0;
    for (ll i = x; i > 0; i /= 10)
    {
        res++;
    }
    return res;
}
int main()
{
    fastio;
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n <= 2)
        {
            cout << "-1\n";
        }
        else if (n == 3)
        {
            cout << 210 << "\n";
        }
        else
        {
            ll x = 1;
            for (ll i = 0; i < n - 1; i++)
            {
                x *= 10;
                x %= 210;
            }
            // if (x == 0)
            // {
            //     cout << 1;
            //     for (ll i = 0; i < n - 1; i++)
            //         cout << "0";
            //     cout << "\n";
            // }
            // else
            // {
            ll ed = (210 - x) % 210;
            ll left = n - 1 - nod(ed);
            cout << 1;
            for (ll i = 0; i < left; i++)
            {
                cout << 0;
            }
            cout << ed << "\n";
            // }
            // cout << 210 /- x << "\n";
        }
    }
}