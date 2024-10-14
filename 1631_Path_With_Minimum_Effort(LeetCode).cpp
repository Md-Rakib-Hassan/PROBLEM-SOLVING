//https://leetcode.com/problems/path-with-minimum-effort

class Solution {
public:
    // Helper function to check if a given cell (r, c) is within the grid bounds
    bool valid(int r, int c, int row, int col) {
        // Return true if (r, c) is within the bounds of the grid
        return !(r < 0 || r >= row || c < 0 || c >= col);
    }


    int minimumEffortPath(vector<vector<int>>& heights) {
        int INF = 1e9 + 9; // A large constant representing "infinity"
        int row = heights.size();  // Number of rows in the grid
        int col = heights[0].size();  // Number of columns in the grid
        
        // Initialize the effort matrix with INF values
        vector<vector<int>> effort(row, vector<int>(col, INF));
        
        // Arrays to help navigate in the four possible directions (right, left, down, up)
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        // A queue for BFS (Breadth-First Search) to explore the grid
        queue<pair<int, int>> q;
        q.push({0, 0});  // Start BFS from the top-left corner
        effort[0][0] = 0;  // The effort to reach the start point is 0

        // BFS loop to explore all the cells in the grid
        while (!q.empty()) {
            auto crnt = q.front(); // Get the current cell
            q.pop();
            int crnt_row = crnt.first;
            int crnt_col = crnt.second;

            // Explore the four possible directions
            for (int i = 0; i < 4; i++) {
                int new_row = crnt_row + dy[i];  // Calculate new row position
                int new_col = crnt_col + dx[i];  // Calculate new column position

                // Check if the new position is valid (within bounds)
                if (valid(new_row, new_col, row, col)) {
                    // Calculate the effort to move to the new cell
                    int new_effort = max(effort[crnt_row][crnt_col], abs(heights[new_row][new_col] - heights[crnt_row][crnt_col]));

                    // If this new path offers less effort, update it
                    if (new_effort < effort[new_row][new_col]) {
                        effort[new_row][new_col] = new_effort;  // Update the effort for this new cell
                        q.push({new_row, new_col});  // Add the new cell to the queue for further exploration
                    }
                }
            }
        }

        // Return the effort required to reach the bottom-right corner (last cell)
        return effort[row-1][col-1];
    }
};
