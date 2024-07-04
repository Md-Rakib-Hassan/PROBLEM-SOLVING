// https://cses.fi/problemset/task/1070/
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

void solve()
{

    int n;
    cin >> n;

    if (n == 2 || n == 3)
        cout << "NO SOLUTION" << nl;
    else
    {
        for (int i = n - 1; i >= 1; i -= 2)
            cout << i << " ";
        for (int i = n; i >= 1; i -= 2)
            cout << i << " ";
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
