// https://leetcode.com/problems/adding-spaces-to-a-string

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans; // To store the final result string
        int j = 0;  // Pointer to track the current position in the 'spaces' vector
        
        // Iterate through each character in the input string
        for (int i = 0; i < s.size(); i++) {
            // Check if the current index matches a space position from the 'spaces' vector
            if (j < spaces.size() && i == spaces[j]) {
                ans.push_back(' '); // Add a space to the result string
                j++; // Move to the next position in the 'spaces' vector
            }
            // Add the current character from the input string to the result
            ans.push_back(s[i]);
        }
        
        // Return the modified string with spaces inserted
        return ans;
    }
};
