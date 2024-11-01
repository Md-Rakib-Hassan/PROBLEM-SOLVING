// https://leetcode.com/problems/reverse-string

class Solution {
public:
    void reverseString(vector<char>& s) {
        // Initialize two pointers, i starting from the beginning and j from the end
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
            // Swap characters at positions i and j
            swap(s[i], s[j]);
        }
    }
};
