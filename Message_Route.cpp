// https://cses.fi/problemset/task/1667/
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    bool vis[n + 1] = {false};
    int parent[n + 1] = {0};
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int vrtx = q.front();
        q.pop();
        for (int ch : v[vrtx])
        {
            if (vis[ch])
                continue;
            q.push(ch);
            parent[ch] = vrtx;
            vis[ch] = true;
        }
    }

    stack<int> ans;
    int child = parent[n];
    if (child)
    {
        ans.push(n);
        while (child)
        {
            ans.push(child);
            child = parent[child];
        }
        cout << ans.size() << nl;
        while (!ans.empty())
        {
            cout << ans.top() << " ";
            ans.pop();
        }
    }
    else
        cout << "IMPOSSIBLE" << nl;

    return 0;
}
