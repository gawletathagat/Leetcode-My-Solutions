class Solution {
public:
    
    vector<vector<int>>dp ;
    int n, m ;
    
    int rec( vector<vector<int>>&grid, int i, int j ) 
    {
        if( i>=n || j>=m ) return INT_MAX ;
        
        if( i== n-1 && j== m-1 ) return grid[i][j] ;
        
        if( dp[i][j] != INT_MAX) return dp[i][j] ;
        
        return dp[i][j] = min( rec(grid, i+ 1, j) , rec( grid, i, j+ 1) ) + grid[i][j] ;
    }
    
    int minPathSum(vector<vector<int>>& grid)
    {
        n = grid.size() ;
        m = grid[0].size() ;
        
        dp.resize(n+1 , vector<int>(m+1, INT_MAX) ) ;
        
        return rec( grid, 0, 0) ; 
    }
};