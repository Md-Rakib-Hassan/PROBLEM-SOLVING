// https://leetcode.com/problems/count-unguarded-cells-in-the-grid

class Solution {
public:
    // Function to check if a cell is within bounds of the grid
    bool isValid(int m, int n, int row, int col) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }

    // Main function to count the number of unguarded cells in the grid
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Create a 2D grid initialized to -1 (unmarked cells)
        vector<vector<int>> arr(m, vector<int>(n, -1));
        
        // Mark guard positions as 0
        for (auto& ch : guards) {
            arr[ch[0]][ch[1]] = 0; // Guard
        }
        
        // Mark wall positions as 1
        for (auto& ch : walls) {
            arr[ch[0]][ch[1]] = 1; // Wall
        }
        
        // Define directions for guard visibility: down, up, right, left
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // Iterate through all cells in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the current cell is a guard
                if (arr[i][j] == 0) {
                    // Check each direction for visibility
                    for (auto& dir : directions) {
                        int temp_i = i, temp_j = j;
                        // Continue marking cells in the current direction until a wall or another guard is encountered
                        while (isValid(m, n, temp_i + dir.first, temp_j + dir.second)) {
                            temp_i += dir.first;
                            temp_j += dir.second;
                            // Stop if the cell contains a guard (0) or a wall (1)
                            if (arr[temp_i][temp_j] == 0 || arr[temp_i][temp_j] == 1) break;
                            // Mark the cell as guarded (5 to distinguish from guards and walls)
                            arr[temp_i][temp_j] = 5;
                        }
                    }
                }
            }
        }

        // Count the number of unguarded cells (still marked as -1)
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == -1) ans++; // Increment count for unguarded cells
            }
        }
        
        // Return the total number of unguarded cells
        return ans;
    }
};
