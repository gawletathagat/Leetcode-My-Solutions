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
    
    void bfs( TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp_parent )
    {
        queue<TreeNode*> q ;
        q.push(root) ;
        
        while( !q.empty() )
        {
            TreeNode* temp = q.front() ; q.pop() ;
            
            if( temp->left)
            {
                mp_parent[temp->left] = temp ;
                q.push( temp->left) ;
            }
            if( temp->right)
            {
                mp_parent[temp->right] = temp ;
                q.push(temp->right) ;
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        //https://www.youtube.com/watch?v=i9ORlEy6EsI
        //we have to store parent of each node, 
        //because we have to travese top and bottom and in trees we can only travese in bottom
        
        unordered_map<TreeNode* , TreeNode* > mp_parent ;
        unordered_map<TreeNode*, bool>vis ;
        
       // if( k ==0 ) return{ root->val} ;
        
        bfs( root, mp_parent );
        
        queue<TreeNode*> q ;
        q.push(target) ;
          vis[target]= true;
        int curr_level= 0;
        
        while( !q.empty() ) 
        {
           int curr_size = q.size() ;
            if( curr_level++ == k)  break;
                  //  curr_level++ ;
            
            for( int i= 0 ; i<curr_size ; i++)
            {
                TreeNode* temp = q.front() ; q.pop() ;
            
               if( temp->left && vis[temp->left] == false )
               {
                   q.push( temp->left) ;
                  vis[temp->left] = true;
               }
               if( temp->right && vis[temp->right] == false)
               {
                   q.push( temp->right) ;
                   vis[temp->right] = true;
               }
               if( mp_parent[temp] && vis[mp_parent[temp]] == false )
               {
                    q.push( mp_parent[temp]) ; 
                   vis[mp_parent[temp]] = true;
               }
            } 
        }
        
        vector<int>ans ;
         while( !q.empty() ) 
         {
             TreeNode* curr = q.front() ;
             q.pop() ;
             ans.push_back(curr->val) ;
         }
        
        return ans ;
    }
};