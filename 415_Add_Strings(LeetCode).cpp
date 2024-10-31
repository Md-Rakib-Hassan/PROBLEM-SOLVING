//https://leetcode.com/problems/add-strings

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";      // Result string to store the sum of num1 and num2
        int carry = 0;        // Variable to store carry from each addition step
        int i = num1.size() - 1, j = num2.size() - 1; // Start indices from the end of each string

        // Loop until we have processed all digits of num1 and num2, and there is no carry left
        while (i >= 0 || j >= 0 || carry) {
            int digit_sum = 0; // Sum of digits at the current position + carry

            // If there are still digits left in num1, add the current digit to digit_sum and move left
            if (i >= 0) digit_sum += (num1[i--] - '0');

            // If there are still digits left in num2, add the current digit to digit_sum and move left
            if (j >= 0) digit_sum += (num2[j--] - '0');

            // Add the carry from the previous step, if any
            if (carry) digit_sum += carry;

            // Calculate the digit to be added to the result by taking modulus of 10
            int digit_sum_last = digit_sum % 10;

            // Update carry for the next step (digit_sum divided by 10)
            carry = digit_sum / 10;

            // Append the calculated digit to the result string (in reverse order)
            ans.push_back(digit_sum_last + '0');
        }

        // Reverse the result string to get the final answer
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
