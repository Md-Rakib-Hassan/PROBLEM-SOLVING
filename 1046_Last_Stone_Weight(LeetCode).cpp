//https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Create a max-heap to store the weights of the stones
        priority_queue<int> pq;

        // Insert all stone weights into the priority queue
        for (auto ch : stones)pq.push(ch);

        // Continue smashing stones until there is at most one stone left
        while (pq.size() > 1) {
            // Take the heaviest stone (top of the heap)
            int top = pq.top();
            pq.pop();

            // Take the second heaviest stone (new top of the heap)
            int secondTop = pq.top();
            pq.pop();

            // Calculate the remaining weight after smashing the two stones
            int smashedWeight = top - secondTop;

            // If there is a non-zero weight left, push it back into the heap
            if (smashedWeight)pq.push(smashedWeight);
        }

        // If no stones are left, push 0 to ensure the heap isn't empty
        pq.push(0);

        // Return the last stone's weight
        return pq.top();
    }
};
