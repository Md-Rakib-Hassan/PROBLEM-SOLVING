// https://atcoder.jp/contests/abc361/tasks/abc361_a
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> v;
    while (n--)
    {
        int val;
        cin >> val;
        v.push_back(val);
    }
    for (int i = 0; i < v.size(); i++)
    {

        cout << v[i] << " ";
        if (i == k - 1)
            cout << x << " ";
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