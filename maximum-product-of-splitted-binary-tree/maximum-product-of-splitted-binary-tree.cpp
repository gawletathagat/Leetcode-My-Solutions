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
    
    void preorder( TreeNode* root, long int& total )
    {
        if( root== NULL) return  ;
        
        total = total + root->val ;
        
        preorder( root->left , total ) ;
        preorder( root->right , total) ;
    }
    
    int max_prod( TreeNode* root, long int& ans , int total )
    {
        if( root == NULL) return 0 ;
        
        long int curr_sum = root->val ;
        
        long int left =  max_prod( root->left  , ans , total) ;
        long int right = max_prod( root->right , ans , total) ;
        
        
        ans = max({ ans , (total-left)*(left) ,(total-right)*(right) }) ;
        
        curr_sum = curr_sum + left + right ;
        
        return curr_sum ;
        
    }
    
    int maxProduct(TreeNode* root)
    {
        long int total = 0;
        preorder( root, total ) ;
        
        long int ans = INT_MIN ;
        
        max_prod( root, ans, total );
        
        return (long)(ans)% 1000000007 ;
    }
};