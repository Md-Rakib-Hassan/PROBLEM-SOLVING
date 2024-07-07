// https://cses.fi/problemset/task/2431
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define with_test_case \
    ll test_no;        \
    cin >> test_no;    \
    for (ll test_case = 1; test_case <= test_no; test_case++)
#define coutcase cout << "Case " << test_case << ": "
#define nl "\n"

void solve()
{

    ll n, tmp;
    cin >> n;
    tmp = n;
    ll digit = 1;
    ll div = 9;
    ll start = 1;

    while (tmp - (div * digit) > 0)
    {
        tmp -= (div * digit);
        digit++;
        div *= 10;
        start *= 10;
    }

    ll number = start + ((tmp - 1) / digit);
    ll ans_idx = (tmp - 1) % digit;
    string s = to_string(number);

    cout << s[ans_idx] << nl;
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
