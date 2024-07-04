// https://cses.fi/problemset/task/1094
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

void solve()
{

    vector<int> v;
    long long len, val, ans = 0;
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> val;
        if (i && val < v[i - 1])
        {
            ans += (v[i - 1] - val);
            val = v[i - 1];
        }
        v.push_back(val);
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