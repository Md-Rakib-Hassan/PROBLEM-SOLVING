//https://leetcode.com/problems/maximum-depth-of-binary-tree
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
    int maxDepth(TreeNode* root) {
        // Base case: If the tree is empty (root is null), return depth as 0
        if (!root) return 0;

        // Recursively calculate the depth of the left subtree
        int leftTree = maxDepth(root->left);

        // Recursively calculate the depth of the right subtree
        int rightTree = maxDepth(root->right);

        // The maximum depth of the current tree is the greater depth between the left and right subtrees, plus 1 for the current node
        return max(leftTree, rightTree) + 1;
    }
};
