// https://cses.fi/problemset/task/1072
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long

void solve()
{

    int n;
    cin >> n;
    cout << 0 << nl;
    for (ll i = 2; i <= n; i++)
    {
        ll total_position = i * i;
        ll total_moves = total_position * (total_position - 1) / 2; // nCr
        ll impossible_moves = (i - 2) * (i - 1) * 4;
        cout << total_moves - impossible_moves << nl;
    }
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