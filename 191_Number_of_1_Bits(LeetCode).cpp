//https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0; // Initialize answer to store the count of '1' bits
        while (n) { // Loop until n becomes zero
            ans += n & 1; // Add 1 to ans if the least significant bit of n is 1
            n = n >> 1; // Right shift n by 1 to check the next bit
        }
        return ans; // Return the count of '1' bits in n
    }
};
