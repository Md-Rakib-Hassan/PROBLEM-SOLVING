//https://leetcode.com/problems/binary-tree-level-order-traversal-ii

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> ans; // This will store the result in a 2D vector.
        queue<pair<TreeNode*, int>> q; // A queue to store the nodes along with their level.
        q.push({root, 0}); // Start by pushing the root node with level 0.

        // BFS loop to traverse the tree level by level.
        while (!q.empty()) {
            auto crnt = q.front(); // Get the current node and its level.
            q.pop(); // Remove the current node from the queue.

            // If the current node is null, skip to the next iteration.
            if (!crnt.first) continue;

            // If the current level doesn't exist in 'ans', create a new level.
            if (ans.size() <= crnt.second) 
                ans.push_back(vector<int>{crnt.first->val});
            else            // Otherwise, add the node value to the existing level.
                ans[crnt.second].push_back(crnt.first->val);

            // Push the left and right children of the current node to the queue with the incremented level.
            q.push({crnt.first->left, crnt.second + 1});
            q.push({crnt.first->right, crnt.second + 1});
        }

        // Reverse the ans vector to make  bottom-up level order.
            reverse(ans.begin(), ans.end());

        return ans; // Return the final bottom-up level order traversal.
        
        
    }
};