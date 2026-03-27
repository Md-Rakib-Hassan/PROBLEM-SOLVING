//https://leetcode.com/problems/path-sum-ii

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
     vector<vector<int>>allPath;
    void dfs(TreeNode* root, int targetSum, vector<int>&cur){
        if(!root)return ;
        targetSum-=root->val;
        cur.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(targetSum==0){
                allPath.push_back(cur);
                
            }
        }
       
        dfs(root->left,targetSum,cur);
        dfs(root->right,targetSum,cur);
        
        cur.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>cur;
        dfs(root,targetSum,cur);

        return allPath;

    }
};