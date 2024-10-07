//https://leetcode.com/problems/number-of-islands


class Solution {
public:
    // A 2D boolean array to mark visited positions
    bool vis[305][305]; 
    
    // Direction vectors for moving up, down, left, and right
    vector<int> dx{1, -1, 0, 0}, dy{0, 0, -1, 1};

    // Function to check if the current cell is a valid land cell to visit
    bool valid(int y, int x, vector<vector<char>>& grid) {
        // Check if coordinates are out of bounds
        if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size()) {
            return false;
        }
        // Check if the current cell is water ('0') or already visited
        else if (grid[y][x] == '0' || vis[y][x])
            return false;
        else
            return true;  // Valid land cell
    }

    // Depth-first search to visit all connected land cells
    void dfs(int y, int x, vector<vector<char>>& grid) {
        // Base case: if the cell is already visited, return
        if (vis[y][x])
            return;
        
        // Mark the current cell as visited
        vis[y][x] = 1;

        // Explore the four directions (up, down, left, right)
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];  // New x-coordinate
            int new_y = y + dy[i];  // New y-coordinate
            // If the new coordinates point to a valid land cell, recurse on it
            if (valid(new_y, new_x, grid))
                dfs(new_y, new_x, grid);
        }
    }

    // Main function to count the number of islands in the grid
    int numIslands(vector<vector<char>>& grid) {
        // Initialize the visited array to all false (no cells visited yet)
        memset(vis, 0, sizeof(vis));
        
        // Vector to store the positions of all land cells
        vector<pair<int, int>> land;
        
        // Traverse the grid to find all land cells ('1')
        for (int iy = 0; iy < grid.size(); iy++) {
            for (int jx = 0; jx < grid[0].size(); jx++) {
                if (grid[iy][jx] == '1') {
                    land.push_back({iy, jx});  // Store land cell coordinates
                }
            }
        }
        
        int ans = 0;  // Counter for the number of islands
        
        // Traverse all land cells found earlier
        for (auto ch : land) {
            // If the current land cell has not been visited, it's a new island
            if (!vis[ch.first][ch.second]) {
                dfs(ch.first, ch.second, grid);  // Start DFS to mark all connected land cells
                ans++;  // Increment the island counter
            }
        }
        
        return ans;  // Return the total number of islands
    }
};
