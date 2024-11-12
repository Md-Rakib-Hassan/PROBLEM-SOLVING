// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Maps to store character mappings from s to t and t to s
        unordered_map<char, char> mp, mp2;
        
        // Assume strings are isomorphic until proven otherwise
        bool ans = 1;
        
        // First loop: Set up the mappings for each character pair in s and t
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] = t[i];   // Map each character in s to the corresponding character in t
            mp2[t[i]] = s[i];  // Map each character in t to the corresponding character in s
        }

        // Second loop: Check that the mappings are consistent
        for (int i = 0; i < s.size(); i++) {
            // If s[i] doesn't map to t[i], strings aren't isomorphic
            if (mp[s[i]] != t[i]) {
                ans = 0;
                break;
            }
            // If t[i] doesn't map to s[i], strings aren't isomorphic
            if (mp2[t[i]] != s[i]) {
                ans = 0;
                break;
            }
        }

        // Return the result
        return ans;
    }
};
