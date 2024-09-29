//https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; // Stores the final result with each level as a separate vector
        queue<pair<TreeNode*, int>> q; // Queue to facilitate BFS, storing nodes and their corresponding level
        q.push({root, 0}); // Start with the root node at level 0
        
        // Perform level order traversal using BFS
        while (!q.empty()) {
            auto crnt = q.front(); // Get the current node and its level
            q.pop(); // Remove the node from the queue
            
            if (!crnt.first) continue; // If the node is null, skip further processing
            
            // If this is the first node at the current level, create a new vector for this level
            if (ans.size() <= crnt.second) ans.push_back(vector<int>{crnt.first->val});
            // Otherwise, add the node's value to the existing vector for this level
            else ans[crnt.second].push_back(crnt.first->val);
            
            // Add the left and right children to the queue, with their level incremented by 1
            q.push({crnt.first->left, crnt.second + 1});
            q.push({crnt.first->right, crnt.second + 1});
        }
        
        return ans; // Return the level order traversal result
    }
};
