//https://leetcode.com/problems/binary-gap

class Solution {
public:
    int binaryGap(int n) {
        // Convert the given number `n` to its binary representation in reverse order
        string binary = ""; // String to store binary representation
        while (n) {
            // Append the least significant bit ('0' or '1') to the binary string
            binary.push_back('0' + (n & 1));
            n /= 2; // Right shift the number by 1 (integer division by 2)
        }

        // Variables to calculate the maximum distance between two '1's in the binary string
        int idx = -1; // Stores the index of the last seen '1'
        int ans = 0;  // Stores the maximum gap found

        // Iterate through the binary representation
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] == '1') { // Check if the current bit is '1'
                if (idx == -1) {
                    // If this is the first '1' encountered, update `idx` with its position
                    idx = i;
                } else {
                    // Calculate the distance to the previous '1', update maximum gap
                    ans = max(ans, i - idx);
                    idx = i; // Update `idx` to the current position
                }
            }
        }

        return ans; // Return the maximum gap between consecutive '1's
    }
};
