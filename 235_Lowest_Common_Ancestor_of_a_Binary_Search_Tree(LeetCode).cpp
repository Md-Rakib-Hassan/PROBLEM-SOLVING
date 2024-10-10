//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while(root) {
            // If both p and q are smaller than root, LCA must be in the left subtree.
            if(root->val > p->val && root->val > q->val) {
                root = root->left;
            }
            // If both p and q are greater than root, LCA must be in the right subtree.
            else if(root->val < p->val && root->val < q->val) {
                root = root->right;
            }
            // If one node is on the left and the other is on the right, or one of them is equal to the root,
            // then the current root is the LCA.
            else return root;
        }
        
        return root; // this line will never be reached as per the steatment
    }
};
