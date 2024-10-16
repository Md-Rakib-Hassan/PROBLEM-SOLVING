//https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        // Vector to store the result of unique quadruplets that sum up to the target
        vector<vector<int>> ans;
        // Map to track already found quadruplets, to avoid duplicates
        map<vector<int>, int> mp;
        // Sort the array to use two-pointer technique effectively
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        
        // First two loops to fix the first two numbers (h and i)
        for (int h = 0; h < sz - 2; h++) {
            for (int i = h + 1; i < sz - 1; i++) {
                int j = i + 1, k = sz - 1;  // Set two pointers, j starts after i and k at the end of array
                
                // Iterate until j and k meet
                while (k > j) {
                    // Calculate the sum of four numbers (nums[h], nums[i], nums[j], nums[k])
                    long long sum = nums[h]*1ll + nums[i]*1ll + nums[j]*1ll + nums[k]*1ll;
                    
                    // If the sum is greater than the target, decrement k to reduce the sum
                    if (sum > target)
                        k--;
                    // If the sum is less than the target, increment j to increase the sum
                    else if (sum < target)
                        j++;
                    // If the sum is equal to the target, it's a valid quadruplet
                    else {
                        // Check if this quadruplet has been already added (avoid duplicates)
                        if (mp[{nums[h], nums[i], nums[j], nums[k]}]) {
                            j++;
                            k--;
                            continue;  // Skip the rest of the loop for this iteration
                        }
                        // Add the valid quadruplet to the result
                        ans.push_back({nums[h], nums[i], nums[j], nums[k]});
                        // Mark this quadruplet as added in the map
                        mp[{nums[h], nums[i], nums[j], nums[k]}]++;
                        // Move both pointers inward to check for other potential combinations
                        j++;
                        k--;
                    }
                }
            }
            // Skip duplicate elements for the first number to avoid redundant work
            while (nums[h] == nums[h + 1]) {
                h++;
                if (h == sz - 1)
                    break;  // Avoid going out of bounds when skipping duplicates
            }
        }

        // Return the result containing all unique quadruplets that sum up to the target
        return ans;
    }
};
