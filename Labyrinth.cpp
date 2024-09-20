//https://cses.fi/problemset/task/1193/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(we) we.begin(), we.end()
#define nl "\n"

char matrix[1000][1000];
int previous[1000][1000];
int n, m;

int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};
char D[] = {'R', 'L', 'D', 'U'};

bool is_valid(int row, int col)
{
    return !(row < 0 || row >= n || col < 0 || col >= m || previous[row][col] != -1 || matrix[row][col] == '#');
}

int main()
{
    cin >> n >> m;
    pair<int, int> src, dest;
    string direction = "";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            matrix[i][j] = ch;
            if (ch == 'A')
                src = {i, j};
            if (ch == 'B')
            {
                dest = {i, j};
                matrix[i][j] = '.';
            }
        }
    }
    memset(previous, -1, sizeof(previous));
    queue<pair<int, int>> q;
    q.push(src);
    previous[src.ff][src.ss] = 4;

    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int r = top.ff + Y[i];
            int c = top.ss + X[i];
            if (is_valid(r, c))
            {
                previous[r][c] = i;
                q.push({r, c});
            }
        }
    }

    if (previous[dest.ff][dest.ss] == -1)
    {
        cout << "NO" << nl;
        return 0;
    }

    int pre = previous[dest.ff][dest.ss];
    int rr = dest.ff, cc = dest.ss;
    while (pre != 4)
    {
        direction.pb(D[pre]);
        rr -= Y[pre];
        cc -= X[pre];
        pre = previous[rr][cc];
    }

    reverse(all(direction));
    cout << "YES" << nl << direction.size() << nl << direction << nl;

    return 0;
}
