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
    
    TreeNode* result = NULL ;
    int max_depth = -1 ;
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        rec( root , 0) ;
        return result ;   
    }
    
    int rec( TreeNode* root , int depth )
    {
        if( root== NULL) return depth;
        
        int left_depth  = rec( root->left ,  depth + 1) ;
        int right_depth = rec( root->right , depth + 1) ;
        
        if( left_depth == right_depth )
        {
            max_depth = max( max_depth , left_depth ) ;
            
            if( max_depth == left_depth )
            {
                result = root ;
            }
        }
        return max( left_depth, right_depth) ;
    }
};