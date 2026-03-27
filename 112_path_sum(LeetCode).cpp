//https://leetcode.com/problems/path-sum


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

    bool dfs(TreeNode* root, int targetSum,int crntSum){
        if(!root)return false;
        crntSum+=root->val;
        if(root->left==nullptr && root->right==nullptr){
            if(crntSum==targetSum)return true;
            else return false;
        }
        bool ans=false;
        ans|=dfs(root->left,targetSum,crntSum);
        ans|=dfs(root->right,targetSum,crntSum);

        return ans;

    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum,0);
    }
};