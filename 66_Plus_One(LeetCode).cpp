// https://leetcode.com/problems/plus-one

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int is_all_zero = 0; // Tracks if all digits are zero after incrementing thats mean all are 9

        // Traverse the digits array from the end to handle carry properly
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] == 9)
            {
                // If the digit is 9, set it to 0 (handle carry-over)
                digits[i] = 0;
                is_all_zero += digits[i]; // Sum the digit (which is 0) to the total
            }
            else
            {
                // If digit is not 9, increment it and add to is_all_zero
                digits[i] += 1;
                is_all_zero += digits[i];
                break; // No further carry needed, exit the loop
            }
        }

        // If is_all_zero is still 0, it means we had a case like 999 -> 000,
        // so we need to add a leading 1 at the start (to make it 1000)
        if (!is_all_zero)
        {
            digits.push_back(1); // Add a 1 at the end
            // Swap elements to move the 1 to the front of the array
            for (int i = digits.size() - 1; i > 0; i--)
            {
                swap(digits[i], digits[i - 1]);
            }
        }

        return digits; // Return the modified vector with incremented value
    }
};
