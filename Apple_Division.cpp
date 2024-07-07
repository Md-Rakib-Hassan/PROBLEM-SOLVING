// https://cses.fi/problemset/task/1623/
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

vector<long long> v;
long long n;

long long diff(long long idx, long long sum1, long long sum2)
{
    if (idx == n)
        return abs(sum1 - sum2);

    long long dif1 = diff(idx + 1, sum1 + v[idx], sum2);
    long long dif2 = diff(idx + 1, sum1, sum2 + v[idx]);

    return min(dif1, dif2);
}

void solve()
{
    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        long long val;
        cin >> val;
        v.push_back(val);
    }
    cout << diff(0, 0, 0) << nl;
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
