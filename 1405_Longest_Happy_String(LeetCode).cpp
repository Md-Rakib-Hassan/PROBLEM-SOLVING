//https://leetcode.com/problems/longest-happy-string

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Max heap (priority queue) to store the count and character pairs.
        // Characters with higher counts will be prioritized (sorted by count in descending order).
        priority_queue<pair<int, char>> q;

        // Only push characters into the queue if their count is greater than 0.
        if (a > 0) q.push({a, 'a'}); // Push count of 'a'
        if (b > 0) q.push({b, 'b'}); // Push count of 'b'
        if (c > 0) q.push({c, 'c'}); // Push count of 'c'}
        
        string ans = "";  // Initialize the result string

        // Process the characters while the priority queue is not empty
        while (!q.empty()) {
            auto first = q.top();  // Get the most frequent character
            q.pop();  // Remove it from the queue

            // Check if the last two characters of the result are the same as the current character
            if (ans.size() >= 2 && ans[ans.size() - 1] == first.second && ans[ans.size() - 2] == first.second) {
                // If yes, we cannot add the current character to avoid having 3 consecutive identical characters
                
                // Check if there is another character available in the queue
                if (q.empty()) break;  // If no other characters are available, break out of the loop
                
                auto second = q.top();  // Get the second most frequent character
                q.pop();  // Remove it from the queue

                ans.push_back(second.second);  // Add the second most frequent character to the result

                // If the count of the second character is still greater than 0 after using it,
                // push it back into the queue with the updated count.
                if (--second.first > 0) q.push(second);

                // Push the first character (the one we skipped) back into the queue for future use
                q.push(first);
            } else {
                // If the last two characters are not the same as the current character, add the current character
                ans.push_back(first.second);  // Add the most frequent character to the result
                
                // If the count of the first character is still greater than 0 after using it,
                // push it back into the queue with the updated count.
                if (--first.first > 0) q.push(first);
            }
        }

        return ans;  // Return the constructed diverse string
    }
};
