// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp; // Create a hashmap to store the occurrence of each number in nums
        
        // Populate the hashmap with numbers from the vector
        for(auto num : nums) mp[num]++;
        
        int max_consecutive = 0; // Initialize variable to track the maximum length of consecutive sequence
        
        // Iterate through each number in the vector
        for(int num : nums) {
            // Check if this number is the start of a new sequence (no number before it in the sequence)
            if(!mp[num - 1]) {
                int curr_consecutive = 0; // Initialize current consecutive count

                // Count the length of the consecutive sequence starting from this number
                while(mp[num++]) curr_consecutive++;
                
                // Update max_consecutive if the current sequence is longer
                max_consecutive = max(max_consecutive, curr_consecutive);
            }
        }
        
        // Return the length of the longest consecutive sequence found
        return max_consecutive;
    }
};
