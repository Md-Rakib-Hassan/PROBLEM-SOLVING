// https://cses.fi/problemset/task/1755

#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

void solve()
{

    string s;
    cin >> s;
    int arr[26];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < s.length(); i++)
    {
        arr[s[i] - 'A']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] & 1)
            odd++;
    }

    if (odd > 1)
        cout << "NO SOLUTION" << nl;
    else
    {
        string ans = "";
        int odd_idx = -1;
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] & 1)
                odd_idx = i;
            else if (arr[i])
            {
                for (int j = 0; j < arr[i] / 2; j++)
                {
                    ans.push_back(char('A' + i));
                }
            }
        }
        string odd_str = "", sna = ans;
        reverse(sna.begin(), sna.end());
        for (int i = 0; i < arr[odd_idx]; i++)
            odd_str.push_back(char('A' + odd_idx));
        cout << ans << odd_str << sna << nl;
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