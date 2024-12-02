// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string word; // Variable to hold each word from the sentence
        stringstream words(sentence); // Stream to split the sentence into words
        int ans = 0; // Variable to count the position of the current word
        bool isFound = false; // Flag to indicate if a prefix match is found

        // Loop through each word in the sentence
        while (words >> word) {
            ans++; // Increment the word position counter

            // Skip checking if the word is shorter than the search word
            if (word.size() < searchWord.size()) continue;

            // Check if the current word starts with the search word
            if (word.substr(0, searchWord.size()) == searchWord) {
                isFound = true; // Set the flag to true if a match is found
            }

            // Exit the loop if a match is found
            if (isFound) break;
        }

        // Return the position if found, otherwise return -1
        return isFound ? ans : -1;
    }
};
