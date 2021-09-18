
class Solution {
public:
    
    
    pair<int,int> dfs( TreeNode* root )
    {
        if( root== NULL) return {0,0} ;
        
        pair<int,int> left = dfs( root->left) ;
        pair<int,int> right = dfs( root->right) ;
        
        int include_root = root->val + left.second + right.second ;
        
        int not_include_root = max( left.first, left.second) + max( right.first , right.second) ;
        
        return {include_root, not_include_root} ;
    }
    
    int rob(TreeNode* root) 
    {
        // first == include root , second == not include root
       pair<int,int> head = dfs( root ) ;
        
        return max( head.first , head.second ) ;
    }
};