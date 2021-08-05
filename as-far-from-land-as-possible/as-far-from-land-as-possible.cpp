class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        // find all the dis , and then iterate on matrix to find the max Diatance
        // we use BFS because , DFS gives us TLE
        
        int n = grid.size() ;
        int m = grid[0].size() ;
       queue<pair<int, int>> q;
        vector<vector<long long int>>ans( n, vector<long long int>(m, INT_MAX) ) ;
        
        for( int i= 0 ; i<n ; i++)
        {
            for( int j= 0 ; j<m ; j++)
            {
                if(grid[i][j]== 1 )
                {
                    q.push({i, j} ) ;
                    ans[i][j] = 0 ;
                }
            }
        }
        
        while(!q.empty() )
        {
            long long int x = q.front().first ;
            long long int y = q.front().second ;
            
            q.pop(); 
            
            if( x+ 1 < n  && y<m)
            {
                if( ans[x+ 1][y] > ans[x][y] + 1) 
                {
                    ans[x+ 1][y] = ans[x][y] + 1;
                    q.push( {x+ 1, y} ) ;
                } 
            }
            if( x-1 >=0  && y<m)
            {
                if( ans[x-1][y] > ans[x][y] + 1)
                {
                    ans[x-1][y] = ans[x][y] + 1;
                    q.push({x-1, y}) ;
                } 
            }
            if( x < n && y-1>=0)
            {
                if( ans[x][y-1] > ans[x][y]+ 1 )
                {
                     ans[x][y-1] = ans[x][y]+ 1;
                    q.push({x, y-1}) ;
                } 
            }
            if( x<n && y+1 <n )
            {
                if( ans[x][y+1] > ans[x][y] + 1)
                {
                     ans[x][y+1] = ans[x][y] + 1; 
                    q.push( {x, y+ 1}) ;
                } 
            }
            
        }
       
        int max_dis = INT_MIN ;
        
        for( int i = 0 ; i<n ; i++)
        {
            for( int j= 0 ; j<m ; j++)
            {
                if( max_dis < ans[i][j] ) max_dis = ans[i][j] ;
            }
        }
        
       if( max_dis == 0 || max_dis== INT_MAX) return -1;
        
        return max_dis ;
        
    }
};