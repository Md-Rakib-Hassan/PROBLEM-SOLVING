// https://leetcode.com/problems/1-bit-and-2-bit-characters

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int sz = bits.size(); // Store the size of the bits vector
        int i = 0;            // Initialize index to iterate through the bits vector

        // Traverse through the bits vector
        while (i < sz) {
            // If the current bit is 1, it indicates a two-bit character (10 or 11)
            // Move the index by 2 (skip the next bit as it's part of this character)
            // Check if this two-bit character ends at the last position
            if (bits[i] && ++i == sz - 1)return false; // If yes, the last character is not one-bit
                
            // Otherwise, increment the index by 1 for a one-bit character
            i++;
        }

        // If we exit the loop, the last character must be one-bit
        return true;
    }
};
