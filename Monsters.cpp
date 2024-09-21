//https://cses.fi/problemset/task/1194/

#include <bits/stdc++.h>
using namespace std;
#define all(we) we.begin(), we.end()
#define pb push_back
#define ff first
#define ss second
#define nl "\n"

int level[1001][1001]; // 2D array to store distance (steps) for each cell
int dir[1001][1001]; // 2D array to store direction taken to reach each cell
char grid[1001][1001]; // 2D array representing the grid input
int X[] = {1, -1, 0, 0}; // X-direction for Right, Left, Down, Up
int Y[] = {0, 0, 1, -1}; // Y-direction for Right, Left, Down, Up
char D[] = {'R', 'L', 'D', 'U'}; // Corresponding characters for directions
int n, m; // Dimensions of the grid

// Function to check if a given cell (row, col) is within grid bounds
bool is_valid(int row, int col)
{
    return !(row < 0 || row >= n || col < 0 || col >= m);
}

int main()
{
    ios_base::sync_with_stdio(false); // Disable synchronization with C I/O for performance
    cin.tie(nullptr); // Untie cin and cout for faster I/O
    cout.tie(nullptr);

    // Read grid dimensions
    cin >> n >> m;

    queue<vector<int>> q; // Queue to store cells for BFS, each with {row, col, step, indicator}
    pair<int, int> src, ext = {-1, -1}; // src: start position, ext: escape point (if found)
    
    // Initialize grid and level arrays
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j]; // Input grid cell
            level[i][j] = -1; // Mark all cells as unvisited
            dir[i][j] = -1; // Initialize direction for all cells

            if (grid[i][j] == 'M') // If it's a monster ('M'), add to queue with indicator 0
            {
                q.push({i, j, 0, 0}); // {row, col, step, 0} - monster
                level[i][j] = 0; // Mark monster's cell as step 0
            }
            if (grid[i][j] == 'A') // If it's the player ('A'), store source position
            {
                src = {i, j};
            }
        }
    }
    
    // Add player's starting point to the queue with indicator 1
    q.push({src.ff, src.ss, 0, 1}); // {row, col, step, 1} - player
    dir[src.ff][src.ss] = -2; // Mark starting point with a special value to trace path later
    int count_a_q = 1; // Counter to track player's instance in the queue

    // BFS starts here
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        int r = top[0], c = top[1], step = top[2], indicator = top[3]; // Extract info from the front of the queue
        
        if (!count_a_q) break; // If no more instance for player in queue then break

        // If player reached the boundary, break the bfs loop
        if (indicator && (r == 0 || c == 0 || r == n - 1 || c == m - 1))
        {
            ext = {r, c};
            break;
        }

        if (indicator) count_a_q--; // Decrease player's instance count if this is a player move as it is poped from queue

        // Update step level for unvisited cells
        if (level[r][c] == -1) level[r][c] = step;

        // Explore 4 possible directions (Right, Left, Down, Up)
        for (int i = 0; i < 4; i++)
        {
            int new_r = r + Y[i];
            int new_c = c + X[i];
            
            // Check if the new position is valid and unvisited
            if (is_valid(new_r, new_c))
            {
                if (level[new_r][new_c] != -1 || grid[new_r][new_c] == '#') continue; // Skip if visited or blocked ('#')

                if (indicator) // If it's the player
                {
                    count_a_q++; // increment player's instance count as it will be pushed in queue
                    dir[new_r][new_c] = i; // Store direction of player
                }

                // Add new position to the queue with updated step
                q.push({new_r, new_c, step + 1, indicator});
                level[new_r][new_c] = step + 1;
            }
        }
    }

    // If no escape point found, print NO and exit
    if (ext.ff == -1)
    {
        cout << "NO" << nl;
        return 0;
    }

    // Trace back the path from escape point to source using directions
    int rr = ext.ff;
    int cc = ext.ss;
    int pre = dir[rr][cc];
    string direction = ""; // To store the path as a string

    while (pre != -2) // -2 marks the start point
    {
        direction.pb(D[pre]); // Append corresponding direction character
        rr -= Y[pre]; // Move in the reverse direction
        cc -= X[pre];
        pre = dir[rr][cc]; // Get the previous direction
    }

    // Reverse the direction string to get the correct path
    reverse(all(direction));

    // Output the result
    cout << "YES" << nl << direction.size() << nl << direction << nl;

    return 0;
}
