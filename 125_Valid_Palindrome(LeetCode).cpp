// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        string str = "", rev;

        // Iterate through each character in the input string
        for (auto ch : s) {
            // If the character is a lowercase letter, append it to 'str'
            if (ch >= 'a' && ch <= 'z') 
                str.push_back(ch);

            // If the character is an uppercase letter, convert it to lowercase 
            // and append it to 'str'
            if (ch >= 'A' && ch <= 'Z') 
                str.push_back(ch + 32);

            // If the character is a digit, append it to 'str'
            if (ch >= '0' && ch <= '9') 
                str.push_back(ch);
        }

        // Create a reversed version of 'str'
        rev = str;
        reverse(rev.begin(), rev.end());

        // Check if the reversed string is equal to the original processed string
        return rev == str;
    }
};
