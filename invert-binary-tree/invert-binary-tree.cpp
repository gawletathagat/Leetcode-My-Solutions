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
    
    TreeNode* rec( TreeNode* root)
    {
        if( root== NULL) return NULL ;
        
       TreeNode* temp = new TreeNode( root->val) ;
        
        temp->right = rec( root->left   ) ;
        temp->left  = rec( root->right  ) ;
        
        return temp ;
    }
    
    TreeNode* invertTree(TreeNode* root)
    {
        // mirror image of tree
       
        return rec( root) ;
    }
};