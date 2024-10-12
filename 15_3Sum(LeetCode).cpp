//https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; // Resultant vector to store all unique triplets
        map<vector<int>, int> mp; // Map to track if a triplet has already been added
        sort(nums.begin(), nums.end()); // Sort the array to make two-pointer technique feasible
        int sz = nums.size(); // Store the size of the input array

        // Loop through each element as the first element of the triplet
        for (int i = 0; i < sz - 1; i++) {
            int j = i + 1, k = sz - 1; // Set two pointers: j starts after i, and k starts at the end
            while (k > j) {
                int sum = nums[i] + nums[j] + nums[k]; // Calculate the sum of the triplet
                if (sum > 0)
                    k--; // If sum is greater than zero, decrease the right pointer (k) as we need to decrease the sum
                else if (sum < 0)
                    j++; // If sum is less than zero, increase the left pointer (j) as we need to increase the sum
                else {
                    // Check if the triplet has already been added to avoid duplicates
                    if (mp[{nums[i], nums[j], nums[k]}]) {
                        j++; // Move both pointers to find new potential triplet
                        k--;
                        continue; // Skip further processing for this triplet
                    }
                    ans.push_back({nums[i], nums[j], nums[k]}); // Add the triplet to the result as this is unique
                    mp[{nums[i], nums[j], nums[k]}]++; // Mark the triplet as added in the map
                    j++; // Move to the next element
                    k--; // Move to the previous element
                }
            }
            // Skip duplicate elements to avoid redundant processing
            while (i + 1 < sz && nums[i] == nums[i + 1]) {
                i++;
            }
        }

        return ans; // Return the vector containing all unique triplets
    }
};
