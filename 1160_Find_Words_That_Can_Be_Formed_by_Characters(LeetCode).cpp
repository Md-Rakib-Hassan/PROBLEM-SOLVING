// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // Create a frequency map for characters in 'chars'
        map<char, int> mp;
        for (auto ch : chars)
            mp[ch]++;
        
        int totalLength = 0; // To store the total length of good words
        
        // Process each word in 'words'
        for (auto word : words) {
            map<char, int> temp = mp; // Make a copy of the original map
            bool good = true;
            
            for (auto ch : word) {
                if (temp[ch] > 0) {
                    temp[ch]--; // Decrement the count if the character exists
                } else {
                    good = false; // Mark as not good if character is not available
                    break;
                }
            }
            
            if (good) {
                totalLength += word.size(); // Add length of good word to total
            }
        }
        
        return totalLength; // Return the total length of all good words
    }
};
