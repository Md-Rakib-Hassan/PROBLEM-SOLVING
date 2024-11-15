// https://leetcode.com/problems/alternating-groups-i

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0, sz = colors.size(); // Initialize the count of alternating groups (ans) to 0 and get the size of the input vector.

        // Iterate through each color in the vector.
        for (int i = 0; i < sz; i++) {
            // Check if the current color is equal to the color two positions ahead (using modulo to wrap around)
            // and if it is different from the color immediately next to it.
            if (colors[i] == colors[(i + 2) % sz] && colors[i] != colors[(i + 1) % sz]) {
                ans++; // Increment the count of alternating groups.
            }
        }

        return ans; // Return the total number of alternating groups.
    }
};
