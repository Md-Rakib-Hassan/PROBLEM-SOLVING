// https://leetcode.com/problems/sort-array-by-parity

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even_odd; // Vector to store even numbers first, then odd numbers

        // First loop: add all even numbers to `even_odd`
        for (auto ch : nums) {
            if (!(ch & 1)) // Check if the number is even (last bit 0)
                even_odd.push_back(ch);
        }

        // Second loop: add all odd numbers to `even_odd`
        for (auto ch : nums) {
            if (ch & 1) // Check if the number is odd (last bit 1)
                even_odd.push_back(ch);
        }

        // Return the reordered array with even numbers first, followed by odd numbers
        return even_odd;
    }
};
