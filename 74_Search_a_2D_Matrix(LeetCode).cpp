//https://leetcode.com/problems/search-a-2d-matrix


//Solution 1 with time complexity O(m+log(n)), where m is the number of rows, and n is the number of columns

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int desire_row = 0; // Initialize the desired row to the first row
        
        // Iterate through each row to find the appropriate row where the target might exist
        for (int i = 0; i < matrix.size(); i++) {
            // If the first element of the current row is less than or equal to the target,
            // update the desired row to the current row index
            if (matrix[i][0] <= target) {
                desire_row = i;
            }
        }
        
        // Perform a binary search on the row where the target is likely to be
        // Returns true if target is found, false otherwise
        return binary_search(matrix[desire_row].begin(), matrix[desire_row].end(), target);
    }
};



//Solution 2 with time complexity O(log(m)+log(n)), where m is the number of rows, and n is the number of columns


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Initialize two pointers: 'i' for the start (0), and 'j' for the end (last row)
        int i = 0, j = matrix.size() - 1;
        int pos = 0; // This will store the row index where the target might be found
        
        // Perform binary search to find the row where the target might exist
        while (j >= i) {
            int mid = (i + j) / 2; // Calculate the mid-point row
            
            // Check if the first element of the mid-row is the target
            if (matrix[mid][0] == target) {
                pos = mid; // If found, set 'pos' to mid and break the loop
                break;
            } 
            // If the first element of the mid-row is greater than the target,
            // narrow the search to the upper half
            else if (matrix[mid][0] > target) {
                j = mid - 1;
            } 
            // If the first element of the mid-row is less than the target,
            // narrow the search to the lower half and update 'pos' to mid
            else {
                i = mid + 1;
                pos = mid;
            }
        }
        
        // Perform a binary search on the row stored in 'pos'
        // Returns true if the target is found, false otherwise
        return binary_search(matrix[pos].begin(), matrix[pos].end(), target);
    }
};
