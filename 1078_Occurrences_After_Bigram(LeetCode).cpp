// https://leetcode.com/problems/occurrences-after-bigram

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        // Create a stringstream object to easily split the text into words
        stringstream s(text);
        string word;
        vector<string> ans, words;

        // Extract words from the stringstream and store them in a vector
        while (s >> word) {
            words.push_back(word);
        }

        // Traverse through the words vector, stopping at size - 2 to avoid out-of-bounds access
        for (int i = 0; i < words.size() - 2; i++) {
            // Check if the current word is 'first' and the next word is 'second'
            if (words[i] == first && words[i + 1] == second) {
                // If true, add the word following 'second' to the answer list
                ans.push_back(words[i + 2]);
            }
        }

        // Return the list of words that follow the given word sequence
        return ans;
    }
};
