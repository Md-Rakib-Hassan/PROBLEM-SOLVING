// https://cses.fi/problemset/task/1618

#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long

void solve()
{

    ll n, ans = 0;
    cin >> n;
    while (n > 1)
    {
        ans += (n / 5);
        n /= 5;
    }
    cout << ans << nl;
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