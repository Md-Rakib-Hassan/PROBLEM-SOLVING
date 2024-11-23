// https://leetcode.com/problems/rotating-the-box

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size(), col = box[0].size(); // Get the dimensions of the box
        
        // Process each row to simulate gravity by moving stones (#) down
        for (int i = 0; i < row; i++) {
            int idx = -1; // Initialize the position where a stone can fall
            for (int j = col - 1; j >= 0; j--) { // Traverse the row from right to left
                if (box[i][j] == '*') // If an obstacle (*) is found
                    idx = -1; // Reset the fall position since stones can't pass obstacles
                
                if (idx == -1 && box[i][j] == '.') // If the current cell is empty and fall position is uninitialized
                    idx = j; // Mark this position as a potential landing spot for stones
                
                if (idx != -1 && box[i][j] == '#') { // If there's a stone (#) and a valid fall position
                    swap(box[i][j], box[i][idx]); // Swap the stone with the empty cell
                    idx--; // Update the fall position to the next empty cell
                }
            }
        }
        
        // Create a new 2D vector to store the rotated box
        vector<vector<char>> ans(col, vector<char>(row, ' ')); 
        
        // Rotate the box 90 degrees clockwise
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans[j][row - i - 1] = box[i][j]; // Map the original (i, j) to the rotated (j, row - i - 1)
            }
        }

        return ans; // Return the rotated box
    }
};
