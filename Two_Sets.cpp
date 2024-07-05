// https://cses.fi/problemset/task/1092/

#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long

void vector_print(vector<ll> v)
{
    cout << v.size() << nl;
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << " ";
    }
    cout << v.back() << nl;
}

void solve()
{
    ll n;
    cin >> n;
    if ((n * (n + 1) / 2) & 1)
        cout << "NO" << nl;
    else
    {
        cout << "YES" << nl;
        if (n & 1)
        {
            ll range = ((n + 1) / 4) - 1;
            vector<ll> s1, s2;
            for (int i = 1; i <= range; i++)
                s1.push_back(i);

            for (int i = n - range; i <= n; i++)
                s1.push_back(i);

            for (int i = range + 1; i < n - range; i++)
                s2.push_back(i);
            vector_print(s1);
            vector_print(s2);
        }
        else
        {
            ll range = n / 4;
            vector<ll> s1, s2;
            for (int i = 1; i <= range; i++)
                s1.push_back(i);

            for (int i = n - range + 1; i <= n; i++)
                s1.push_back(i);

            for (int i = range + 1; i <= n - range; i++)
                s2.push_back(i);
            vector_print(s1);
            vector_print(s2);
        }
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