//https://leetcode.com/problems/binary-tree-inorder-traversal

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
    // Helper function to perform in-order traversal and store values in `ans`
    void traverse(TreeNode* root, vector<int>& ans) {
        if (!root) return; // Base case: if the current node is null, return
        traverse(root->left, ans); // Traverse the left subtree
        ans.push_back(root->val); // Visit the current node (in-order step)
        traverse(root->right, ans); // Traverse the right subtree
    }

    // Main function to return in-order traversal of the tree as a vector
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans; // Vector to store the in-order traversal result
        traverse(root, ans); // Start traversal from the root node
        return ans; // Return the result after traversal is complete
    }
};
