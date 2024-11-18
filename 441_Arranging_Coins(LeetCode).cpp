//https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        // The formula to find the number of complete rows is derived from the sum of 
        // the first k natural numbers: k * (k + 1) / 2 <= n.
        // Rearranging gives: k = (-1 + sqrt(1 + 8 * n)) / 2.
  
        // Calculate and return the maximum number of complete rows (k)
        return ((sqrt(8ll * n + 1) - 1) / 2);
    }
};
