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
    
//     bool check( TreeNode* root)           // fail in  [1,2,3,5,null,7,8]
//     {
//         if( root== NULL) return true; 
        
//         if( root->left== NULL && root->right== NULL) return true ;
        
//         if( root->left== NULL && root->right ) return false; 
        
//         if( root->left && root->right== NULL) return true ;
        
//         return check(root->left ) && check( root->right ) ;
//     }
    
    bool isCompleteTree(TreeNode* root) 
    {
        // using BFS 
        queue<TreeNode*> q ;
        q.push(root) ;
        int isEmpty = 0 ;
        
        while( !q.empty() )
        {
            TreeNode* temp = q.front() ;
            q.pop() ;
            
            if( temp->left)
            {
                if( isEmpty== 1) return false ;
                q.push(temp->left) ;
            }
            else 
                isEmpty= 1;
            
            if( temp->right)
            {
                if( isEmpty== 1) return false ;
                q.push(temp->right) ;
            }
            else 
                isEmpty = 1;
            
        }
        
        return true;
        
    }
};