class Solution {
public:
    
    void dfs( int i, int j , vector<vector<int>>&vis , vector<vector<int>>&big_grid )
    {
        if( i<0 || i>= big_grid.size()  || j<0 ||j>= big_grid[0].size() || vis[i][j] == 1 || big_grid[i][j] == 1 ) return ;
        vis[i][j] = 1;
        
        dfs( i+1 , j , vis, big_grid) ;
        dfs( i , j+1 , vis, big_grid) ;
        dfs( i-1 , j , vis, big_grid) ;
        dfs( i , j-1 , vis, big_grid) ;
   
    }
 
    int regionsBySlashes(vector<string>& grid) 
    {
      // we create a 3*grid and store the values
           // if / =>   0 0 1
           //           0 1 0       // after than we creat a DFS
           //           1 0 0
           
            // if \\ => 1 0 0 
           //           0 1 0    
           //           0 0 1
        
        int n = grid.size() ;
        vector<vector<int>>big_grid(n*3, vector<int>(n*3 , 0) );
        
        for( int i= 0 ; i<grid.size() ; i++)
        {
            string temp = grid[i] ;
            for( int j = 0 ; j<n ; j++)
            {
                if(temp[j] == '/')
                {
                    big_grid[i*3+2][j*3] = 1;
                    big_grid[i*3+1][j*3+1] = 1;
                    big_grid[i*3][j*3+2] = 1;
                    
                }
                else if( temp[j] == '\\')
                {
                    big_grid[i*3 ][j*3 ] = 1;
                    big_grid[i*3+ 1 ][j*3+ 1 ] = 1;
                    big_grid[i*3+ 2 ][j*3+ 2 ] = 1;
                }
            }
        }

        vector<vector<int>>vis( n*3, vector<int>(n*3, 0) );
        int count = 0 ;
        for( int i= 0 ; i<n*3 ; i++ )
        {
            for( int j= 0 ; j<n*3; j++)
            {
                if( !vis[i][j] && big_grid[i][j] == 0)
                {
                    count++;
                    dfs(i,j,vis,big_grid);
                }
            }
        }
        return count;
           
    }    
};