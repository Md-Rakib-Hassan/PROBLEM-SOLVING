// https://leetcode.com/problems/find-the-original-typed-string-i

class Solution {
public:
    int possibleStringCount(string word) {
        int side_occ = 0; // Counter for consecutive identical characters

        // Loop through the string up to the second last character
        for (int i = 0; i < word.size() - 1; i++) {
            // If the current character is the same as the next, increment the counter
            if (word[i] == word[i + 1]) 
                side_occ++;
        }
        
        // Increment side_occ by 1 to include the initial substring or unique characters in the count
        return ++side_occ;
    }
};
