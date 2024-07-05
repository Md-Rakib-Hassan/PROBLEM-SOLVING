// https://cses.fi/problemset/task/1617/
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long
const int M = 1e9 + 7;

ll bin_exp(ll a, ll b)
{
    ll ans = 1;

    while (b)
    {
        if (b & 1)
            ans = (ans * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return ans % M;
}

void solve()
{

    ll n;
    cin >> n;
    cout << bin_exp(2, n) << nl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}