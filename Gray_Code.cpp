// https://cses.fi/problemset/task/2205

#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

string binary_to_gray(string s, int bit)
{
    string gray = "";
    gray.push_back(s[0]);
    for (int i = 1; i < bit; i++)
    {
        int xr = (s[i - 1] - '0') ^ (s[i] - '0');
        gray.push_back(xr + '0');
    }
    return gray;
}

void binary_print(int num, int bit)
{
    string bin = "";
    while (num)
    {
        if (num & 1)
        {
            bin.push_back('1');
        }
        else
            bin.push_back('0');
        num >>= 1;
    }
    reverse(bin.begin(), bin.end());
    if (bin.size() < bit)
        bin.insert(0, bit - bin.size(), '0');

    cout << binary_to_gray(bin, bit) << nl;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < pow(2, n); i++)
        binary_print(i, n);
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