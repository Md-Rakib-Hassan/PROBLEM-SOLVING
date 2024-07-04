// https://cses.fi/problemset/task/1071
#include <bits/stdc++.h>
using namespace std;
#define with_test_case \
    int test_no;       \
    cin >> test_no;    \
    for (int test_case = 1; test_case <= test_no; test_case++)
#define coutcase cout << "Case " << test_case << ": "
#define nl "\n"
#define ll long long

void solve()
{
    ll x, y, ans = 0;
    cin >> y >> x;

    if (y > x)
    {
        if (y & 1)
            ans = (y - 1) * (y - 1) + x;
        else
            ans = y * y - x + 1;
    }
    else if (x > y)
    {
        if (x & 1)
            ans = x * x - y + 1;
        else
            ans = (x - 1) * (x - 1) + y;
    }
    else
        ans = x * x - x + 1;
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
    with_test_case solve();
    return 0;
}