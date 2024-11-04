// https://leetcode.com/problems/to-lower-case

class Solution {
public:
    string toLowerCase(string s) {
        // Iterate through each character in the string
        for(int i = 0; i < s.size(); i++) {
            // Check if the character is an uppercase letter (between 'A' and 'Z')
            if(s[i] >= 'A' && s[i] <= 'Z')
                // Convert the uppercase character to lowercase by adding a space (ASCII value 32)
                s[i] = char(s[i] + ' ');
        }
        // Return the modified string
        return s;
    }
};
