// https://leetcode.com/problems/rank-transform-of-an-array

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp; // A map to store unique elements of the array with their ranks

        // Populate the map with elements from the array and assign a temporary value of 1
        for (auto ch : arr)
            mp[ch] = 1;

        int i = 0; // Rank counter
        // Assign ranks to each unique element in the map, starting from 1
        for (auto ch : mp) {
            mp[ch.first] = ++i; // Increment the rank and assign it to the element
        }

        vector<int> ans; // Resultant vector to store the ranks corresponding to the original array
        // Replace each element in the original array with its rank from the map
        for (auto ch : arr) {
            ans.push_back(mp[ch]);
        }

        return ans; // Return the ranked array
    }
};
