// https://cses.fi/problemset/task/1622

#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

void solve()
{

    string s;
    cin >> s;

    vector<string> all_permutation;

    sort(s.begin(), s.end());

    all_permutation.push_back(s);
    while (next_permutation(s.begin(), s.end()))
        all_permutation.push_back(s);

    cout << all_permutation.size() << nl;
    for (auto ch : all_permutation)
        cout << ch << nl;
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