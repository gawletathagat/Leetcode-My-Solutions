class Solution {
public:
    
    void dfs( int i, int j , vector<vector<int>>&grid, vector<vector<bool>>&vis )
    {
        if( i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == 1 || vis[i][j] == true ) return ;
        
        vis[i][j] = 1;
        
        dfs( i+1, j, grid, vis);
        dfs( i, j+1, grid, vis);
        dfs( i-1, j, grid, vis);
        dfs( i, j-1, grid, vis);
    }
    
    int closedIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size() ;
        
        vector<vector<bool>>vis(n , vector<bool>(m, false) ) ;
        
        for( int i = 0 ; i<n ; i++)
        {
            if( grid[i][0] == 0)
            dfs( i , 0 , grid, vis) ;
        }
        for( int i = 0 ; i<n ; i++)
        {
            if( grid[i][m-1] == 0)
            dfs( i, m-1 , grid, vis) ;
        }
        for( int j= 0 ; j<m ; j++)
        {
            if( grid[0][j] == 0)
            dfs( 0 , j , grid, vis) ;
        }
        for( int j = 0 ; j<m ; j++)
        {
            if( grid[n-1][j] == 0)
            dfs( n-1, j , grid, vis) ;
        }
        
        int island= 0;
        for( int i= 0; i<n; i++)
        {
            for( int j= 0 ; j<m ; j++)
            {
                if( vis[i][j] == false && grid[i][j] == 0)
                {
                    dfs( i, j, grid, vis) ;
                    
                        island++;
                }
            }
        }
        return island ;
    }
};