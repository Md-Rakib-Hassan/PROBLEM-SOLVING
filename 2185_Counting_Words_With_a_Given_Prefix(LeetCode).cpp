// https://leetcode.com/problems/counting-words-with-a-given-prefix

class Solution {
public:

    int prefixCount(vector<string>& words, string pref) {
        int ans = 0; // Initialize the counter for words with the given prefix
        
        // Iterate through each word in the list
        for (auto ch : words) {
            // Extract the substring of the word with the same length as the prefix
            string tmp = ch.substr(0, pref.size());
            
            // Check if the extracted substring matches the prefix
            if (pref == tmp) {
                ans++; // Increment the counter if there is a match
            }
        }
        return ans; // Return the total count of matching words
    }
};
