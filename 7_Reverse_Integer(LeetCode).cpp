// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        // Initialize a variable to store the reversed number
        int ans = 0;
        // Define the boundary to check for overflow
        int bound = INT_MAX / 10;

        // Loop until all digits of 'x' are processed
        while(x) {
            // Extract the last digit of 'x'
            int last_digit = x % 10;

            // Check for potential overflow or underflow before multiplying
            //We dont have any headache with the 10th position number as they are giving a int number so it would be maximum 1 or 2. So if till 9th position is not greater then the bound or less then -bound then it wouldn't overflow.
            if (ans > bound || ans < bound * -1) 
                return 0;  // Return 0 if reversing the number would overflow

            // Add the last digit to the reversed number
            ans = ans * 10 + last_digit;

            // Remove the last digit from 'x'
            x /= 10;
        }

        // Return the reversed number
        return ans;
    }
};
