//https://leetcode.com/problems/cousins-in-binary-tree-ii

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // Queue to perform a level-order traversal, storing pairs of current node and its parent.
        queue<pair<TreeNode*, TreeNode*>> q;
        // Push the root node twice (as itself and as its "parent").
        q.push({root, root});

        // Perform level-order traversal.
        while (!q.empty()) {
            // Get the size of the current level (number of nodes at this level).
            int this_level_node_sz = q.size();
            int level_sum = 0;  // To accumulate the sum of node values at this level.
            vector<pair<TreeNode*, TreeNode*>> this_level;  // Vector to store nodes at this level.
            unordered_map<TreeNode*, int> parent_sum;  // Map to track the sum of the values of children for each parent node.

            // Process all nodes at the current level.
            while (this_level_node_sz--) {
                auto crnt = q.front();  // Get the current node and its parent.
                q.pop();  // Remove it from the queue.
                if (!crnt.second) continue;  // If the current node is null, skip.

                this_level.push_back(crnt);  // Add the current node to the list of this level's nodes.
                level_sum += crnt.second->val;  // Add the current node's value to the level sum.
                parent_sum[crnt.first] += crnt.second->val;  // Add the current node's value to its parent's sum.
            }

            // Update each node's value with the level sum minus its parent's accumulated value.
            for (auto &node : this_level) {
                node.second->val = level_sum - parent_sum[node.first];  // Update the node's value.
                // Push the node's left and right children to the queue for the next level.
                q.push({node.second, node.second->left});
                q.push({node.second, node.second->right});
            }
        }

        // Return the modified root of the tree.
        return root;
    }
};
