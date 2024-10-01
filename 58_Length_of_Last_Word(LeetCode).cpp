//https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;                  // Variable to store the length of the last word
        bool isWordStarted = false;      // Boolean flag to indicate when a word starts

        // Loop through the string in reverse to find the last word
        for (int i = s.size() - 1; i >= 0; i--) {
            // If the current character is a space and a word hasn't started yet, continue skipping spaces
            if (s[i] == ' ' && !isWordStarted) continue;
            
            // If a word has started and we encounter a space, break the loop (word has ended)
            else if (isWordStarted && s[i] == ' ') break;
            
            // If it's a non-space character, the word has started
            else isWordStarted = true;    // Mark that the word has started
            
            length++;    // Increase the length of the word
        }

        return length;   // Return the length of the last word
    }
};
