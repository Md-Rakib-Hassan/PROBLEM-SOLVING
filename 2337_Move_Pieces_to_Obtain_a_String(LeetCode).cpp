// https://leetcode.com/problems/move-pieces-to-obtain-a-string

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size(); // Initialize variables: n for size of the strings

        // Loop through both strings using i and j.
        for (int i = 0, j = 0; i < n || j < n; i++, j++) {
            // Skip all '_' characters in the start string.
            while (i < n && start[i] == '_') i++;
            // Skip all '_' characters in the target string.
            while (j < n && target[j] == '_') j++;

            // If characters mismatch, return false.
            if (start[i] != target[j]) return false;

            // Check constraints for 'L' and 'R' transformations:
            // 'L' can only move to the left; i (start) must not be less than j (target).
            if (start[i] == 'L' && i < j) return false;
            // 'R' can only move to the right; i (start) must not be greater than j (target).
            if (start[i] == 'R' && i > j) return false;
        }

        // If all conditions are satisfied, return true.
        return true;
    }
};
