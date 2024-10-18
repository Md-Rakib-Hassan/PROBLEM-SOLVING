//https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Use unordered_map for faster lookups where the key is a sorted string
        // and the value is a vector of strings (anagrams)
        unordered_map<string, vector<string>> mp;

        // Iterate through each string in the input vector
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i]; // Store the original string
            sort(strs[i].begin(), strs[i].end()); // Sort the string to create a key for the map
            mp[strs[i]].push_back(str); // Add the original string to the map under the sorted string as the key
        }

        // Create a vector to store the grouped anagrams
        vector<vector<string>> ans;

        // Iterate through the unordered_map and collect the anagram groups
        for (auto ch : mp) {
            ans.push_back(ch.second); // Add each group of anagrams to the result
        }

        return ans; // Return the grouped anagrams
    }
};
