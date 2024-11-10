//https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        // Initialize the answer string to store the result
        string ans = "";
        
        // Set up pointers to the last characters of both strings
        int i = a.size() - 1;
        int j = b.size() - 1;
        
        // Initialize carry to handle sums greater than 1
        int carry = 0;
        
        // Loop through both strings from the end to the beginning
        while (i >= 0 || j >= 0) {
            int sum = carry;  // Start with the carry value
            
            // Add the current digit of 'a' to sum, if within bounds, and move pointer left
            if (i >= 0) sum += a[i--] - '0';
            
            // Add the current digit of 'b' to sum, if within bounds, and move pointer left
            if (j >= 0) sum += b[j--] - '0';
            
            // Append the binary result (0 or 1) of sum modulo 2 to 'ans'
            ans.push_back((sum % 2) + '0');
            
            // Update carry for the next iteration (1 if sum is 2 or 3, otherwise 0)
            carry = sum > 1;
        }
        
        // If there's any remaining carry, add it as the most significant bit
        if (carry) ans.push_back('1');
        
        // Since the result is built backwards, reverse it to get the correct order
        reverse(ans.begin(), ans.end());
        
        return ans;  // Return the binary sum as a string
    }
};
