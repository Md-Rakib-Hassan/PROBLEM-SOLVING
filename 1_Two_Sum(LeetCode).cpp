// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create an unordered_map to store the frequency of each number
        // along with its index. The key is the number, and the value is a pair:
        // - first: count of occurrences of the number for make sure the element exists
        // - second: index of the number in the nums array
        unordered_map<int, pair<int, int>> mp;

        // Loop through each element of the nums array
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the complement that we need to find in the map
            int complement = target - nums[i];

            // Check if the complement exists in the map (i.e., we've already seen it)
            // If so, return the current index 'i' and the index of the complement
            if (mp[complement].first) return {i, mp[complement].second};

            // Increment the count of the current number in the map
            // and store its index
            mp[nums[i]].first++;
            mp[nums[i]].second = i;
        }

        // this line will never be reached as per the steatment
        return {};
    }
};
