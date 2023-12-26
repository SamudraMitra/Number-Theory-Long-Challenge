#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return ((a / gcd(a, b)) * b);
}
int main()
{
    ll t;
    t = 1;
    while (t--)
    {
        ll n;
        cin >> n;
        if ((n == 1) || (n == 2))
        {
            cout << n << "\n";
            return 0;
        }
        if (n % 2)
        {
            cout << n * (n - 1) * (n - 2) << "\n";
        }
        else
        {
            cout << max(lcm(lcm((n - 1), (n)), (n - 3)), lcm(lcm((n - 1), (n - 2)), (n - 3))) << "\n";
        }
    }
}