//https://leetcode.com/problems/power-of-three/description/

class Solution {
public:
    bool isPowerOfThree(int n) {
        // If n is less than or equal to 0, it cannot be a power of three.
        if (n <= 0) return false;

        // Continuously divide n by 3 as long as it is divisible by 3.
        while (n % 3 == 0) {
            n /= 3; // Reduce n by dividing it by 3.
        }

        // If n becomes 1 after all divisions, it means n is a power of three.
        return n == 1;
    }
};
