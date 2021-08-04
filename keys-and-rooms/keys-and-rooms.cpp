class Solution {
public:
    
    void dfs( int i, vector<vector<int>>&rooms, vector<bool>&vis )
    {
        vis[i] = true;
        
        for( int k = 0 ; k< rooms[i].size() ; k++)
        {
            if( vis[rooms[i][k]] == false ) 
            {
                dfs( rooms[i][k] , rooms , vis) ;
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        
        int n = rooms.size() ;
        vector<bool> vis(n , false ) ;
        
         dfs( 0 , rooms, vis) ;
        
        for( int i= 0 ; i<n ; i++)
        {
            if( vis[i] == false) return false;
        }
        return true;
        
    }
};