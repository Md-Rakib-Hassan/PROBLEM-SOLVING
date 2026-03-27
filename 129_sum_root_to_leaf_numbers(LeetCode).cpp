//https://leetcode.com/problems/sum-root-to-leaf-numbers


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

    int dfs(TreeNode* root, int sum){
        if(!root)return 0;
        sum*=10;
        sum+=root->val;
        int ans=0;
        if(root->left==nullptr && root->right==nullptr)return sum;
        
        ans+=dfs(root->left,sum);
        ans+=dfs(root->right,sum);

        return ans;

    }

    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};