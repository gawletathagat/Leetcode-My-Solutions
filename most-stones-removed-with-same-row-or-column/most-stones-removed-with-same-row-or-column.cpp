class Solution {
public:
    
    void dfs( int currStone , vector<vector<int>>&stones, vector<int>&vis )
    {
        vis[currStone] = 1;
        
        int row = stones[currStone][0] ;
        int col = stones[currStone][1] ;
        
        for( int i= 0 ; i<stones.size() ; i++)
        {
            if( vis[i] ==0 && (stones[i][0]== row || stones[i][1]== col ) )
            {
                dfs(i, stones, vis ) ;
            }
        }
        
    }
    
    int removeStones(vector<vector<int>>& stones)
    {
        // is this readlly a graph Q ? How do you know ? 
        // we can solve this Q with DFS( number of island )   or using Disjoint set 
        
        //M-1 DFS , visited array
        
        int n = stones.size() ;
        
        vector<int>vis(n, 0 ) ;
        int groups = 0;
        
        for( int i= 0 ; i<n ; i++)
        {
            if( vis[i] == 0)
            {
                groups++ ;
                dfs(i , stones, vis) ; 
            }
        }
        
        return n - groups;
    }
};