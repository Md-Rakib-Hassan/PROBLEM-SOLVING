//https://leetcode.com/problems/sum-of-left-leaves

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // Initialize a queue to store pairs of TreeNode pointers and a boolean flag
        // The flag indicates whether the node is a left child (true for left, false for right)
        queue<pair<TreeNode*, bool>> q;
        int ans = 0; // Variable to accumulate the sum of left leaf nodes
        q.push({root, false}); // Start with the root node, marked as not a left child
        
        // Process nodes in the queue
        while (!q.empty()) {
            auto crnt = q.front(); // Get the current node and its "left child" status
            q.pop();
            
            // Skip processing if the current node is null
            if (!crnt.first) continue;
            
            // Check if the node is a left leaf (left child with no children)
            if (crnt.second && !crnt.first->left && !crnt.first->right) {
                ans += crnt.first->val; // Add the value to the sum if it's a left leaf
            }
            
            // Add the left and right children of the current node to the queue
            q.push({crnt.first->left, true});  // Left child marked as true
            q.push({crnt.first->right, false}); // Right child marked as false
        }
        
        return ans; // Return the sum of values of all left leaf nodes
    }
};
