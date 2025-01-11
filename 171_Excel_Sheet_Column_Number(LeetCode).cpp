//https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sz = columnTitle.size(), ans = 0; // Get the size of the column title and initialize the result variable
        
        // Iterate through each character in the column title
        for (int i = 0; i < sz; i++) {
            // Convert the character to its corresponding number (A=1, B=2, ..., Z=26)
            // Multiply by 26 raised to the power of its position from the right (zero-indexed)
            ans += (columnTitle[i] - 'A' + 1) * pow(26, (sz - i - 1));
        }
        
        return ans; // Return the final computed column number
    }
};
