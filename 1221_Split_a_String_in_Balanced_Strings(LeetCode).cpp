// https://leetcode.com/problems/split-a-string-in-balanced-strings/

class Solution {
public:
    int balancedStringSplit(string s) {
        // Initialize counters for 'L' and 'R' and the result variable
        int L_count = 0, R_count = 0, ans = 0;

        // Iterate through each character in the string
        for (int i = 0; i < s.size(); i++) {
            // Increment the respective counter based on the character
            if (s[i] == 'L') L_count++;
            else R_count++;

            // Check if the counts of 'L' and 'R' are equal
            if (L_count == R_count) ans++;  // Increment the result as we found a balanced substring
        }

        // Return the total count of balanced substrings
        return ans;
    }
};
