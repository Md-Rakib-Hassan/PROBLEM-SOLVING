// https://leetcode.com/problems/buddy-strings

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        // Copy strings s and goal for sorting
        string sorted_s = s, sorted_goal = goal;
        bool repeat_present = 0; // Flag to check if any character repeats in 's'
        int not_matched = 0;     // Counter for don't matched characters in 's' and 'goal'
        
        // Sort both strings to check if they are permutations of each other
        sort(sorted_s.begin(), sorted_s.end()); 
        sort(sorted_goal.begin(), sorted_goal.end());
        
        // Iterate through the characters of the strings
        for(int i = 0; i < min(s.size(), goal.size()); i++) {
            // Check if there are repeating characters in 's'
            if(i != min(s.size(), goal.size()) - 1 && sorted_s[i] == sorted_s[i + 1]) {
                repeat_present = 1;
            }
            // Count mismatched characters between 's' and 'goal'
            if(s[i] != goal[i]) not_matched++;
        }
        
        // Return false if:
        // - 's' and 'goal' are identical but have no repeating characters (one swapping is impossible)
        // - More than 2 mismatched positions exist (swapping can't fix it)
        // - Sorted strings don't match (not permutations of each other)
        // Otherwise, return true.
        return !not_matched && !repeat_present ? false : not_matched > 2 ? false : sorted_s != sorted_goal ? false : true;
    }
};
