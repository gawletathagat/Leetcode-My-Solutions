class Solution {
public:
    
    
    int dfs( int i, int j , vector<vector<int>>&vis, vector<vector<int>>&grid )
    {
        if( i<0 || j<0 || i>=grid.size() ||j>=grid[0].size() || vis[i][j]==1 || grid[i][j]==0) return 0;
            
        vis[i][j] = 1;
        int ans = 0;
        ans = ans + dfs( i+ 1, j, vis, grid) ;
        ans = ans + dfs( i, j+ 1, vis, grid) ;
        ans = ans + dfs( i-1, j, vis, grid ) ;
        ans = ans + dfs( i, j-1, vis, grid) ;
        
        //cout<<ans<<endl;
        return ans+1 ;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        // M-1 DFS
        // M-2 DSU 
        int n = grid.size() ;
        int m  = grid[0].size() ;
        int max_area = 0;
        
        vector<vector<int>>vis(n+ 1, vector<int>(m+ 1, 0)) ;
        
        for( int i= 0 ; i<n ; i++)
        {
            for( int j = 0 ; j<m ; j++)
            {
                if( vis[i][j] ==0 && grid[i][j] == 1)
                {
                    int curr_max = 0 ;
                    
                    curr_max = dfs( i, j, vis, grid ) ;
                    
                    max_area = max( max_area , curr_max ) ;
                }
            }
        }
        return max_area ;  
    }
};