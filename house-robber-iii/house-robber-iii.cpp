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
    pair<int,int> dfs(TreeNode* root )
    {
        if( root== NULL) return {0,0} ;
        
        pair<int,int>left = dfs( root->left) ;
        pair<int,int>right = dfs( root->right) ;
        
        int choice1 = root->val + left.second + right.second  ; // not select from left and right tree
        
        int choice2 = max(left.first, left.second) + max( right.first, right.second) ;
        
        return {choice1, choice2} ;
    }
    
    int rob(TreeNode* root)
    {
        // first = include, second = not include root
        pair<int,int>decide = dfs( root );
        
        return max( decide.first , decide.second) ;
    }
};