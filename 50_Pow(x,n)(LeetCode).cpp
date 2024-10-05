// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {

        double ans = 1;  // Initialize result as 1

        // Continue while n is non-zero
        while (n) {
            // Case when n is positive
            if (n > 0) {
                // If n is odd (n & 1 checks if the least significant bit is 1)
                if (n & 1) {
                    ans *= x;  // Multiply current result by x so that we can reduce the power and make it even
                    n--;       // Decrease n by 1 to make it even
                } else {
                    x *= x;    // Square x (for even n) as we can write 2^6 = 4^3
                    n >>= 1;   // Right shift n to divide by 2 by making the base square the power will be half like 2^6 = 4^3. 6 came to 3
                }
            } else {
                // Case when n is negative
                // If n is odd (negative)
                if (n & 1) {
                    ans /= x;  // Divide current result by x (handling negative exponent) same thinghs but opposite.
                    n++;       // Increase n to make it closer to zero
                } else {
                    x *= x;    // Square x (same as before)
                    n >>= 1;   // Right shift n to divide by 2
                }
            }
        }
        return ans;  // Return the calculated power
    }
};
