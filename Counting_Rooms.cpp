// https://cses.fi/problemset/task/1192/
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define nl "\n"

int X[] = {0, 1, -1, 0};
int Y[] = {1, 0, 0, -1};
bool vis[1005][1005] = {false};
char mat[1005][1005];
int n, m;
bool is_valid(int x, int y)
{
    if ((x >= 0 && x < m || y >= 0 && y < n) && !vis[x][y] && mat[x][y] == '.')
        return true;
    return false;
}

int main()
{

    cin >> n >> m;

    vector<pair<int, int>> cordinates;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            mat[i][j] = ch;
            if (ch == '.')
                cordinates.push_back({i, j});
        }
    }
    int room = 0;
    for (auto cord : cordinates)
    {
        if (vis[cord.ff][cord.ss])
            continue;
        queue<pair<int, int>> q;
        q.push({cord.ff, cord.ss});
        vis[cord.ff][cord.ss] = true;
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int new_x = top.ff + X[i];
                int new_y = top.ss + Y[i];
                if (is_valid(new_x, new_y))
                {
                    q.push({new_x, new_y});
                    vis[new_x][new_y] = true;
                }
            }
        }
        room++;
    }
    cout << room << nl;

    return 0;
}
