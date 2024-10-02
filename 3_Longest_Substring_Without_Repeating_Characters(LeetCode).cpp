//https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;  // Variable to store the length of the longest substring found
        int i = 0, j = 0;  // Two pointers: 'i' expands the window, 'j' shrinks it when a duplicate is found
        map<char, int> mp;  // HashMap to keep track of the characters and their occurrences in the current window

        // Loop to iterate through the string with the 'i' pointer
        while (i < s.size()) {
            // If the current character is not in the map (or its value is 0), it's not a duplicate
            if (!mp[s[i]]) {
                mp[s[i]]++;  // Mark the character as seen in the map
                i++;  // Move the 'i' pointer to expand the window
            } else {
                // If the character is a duplicate, shrink the window by moving 'j'
                mp[s[j]]--;  // Remove the character at 'j' from the map (or decrease its count)
                j++;  // Move the 'j' pointer to shrink the window
            }
            
            // Update the answer with the maximum window size found so far
            ans = max(ans, abs(i - j));  
        }

        return ans;  // Return the length of the longest substring without repeating characters
    }
};
