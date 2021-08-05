class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        // use BFS in Shortest Path: Q
        
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        queue<pair<long long int , long long int >> q ;
        
        vector<vector<long long int>>ans(n, vector<long long int>( m, INT_MAX) ) ;
        
        for( int i= 0 ; i<n ; i++)
        {
            for( int j= 0 ;j<m ; j++)
            {
                if( grid[i][j] == 2)
                {
                    q.push({i, j}) ;
                    ans[i][j] = 0;
                }
                if( grid[i][j] == 0) 
                    ans[i][j] = 0;
            }
        }
        
        while( !q.empty() )
        {
            long long int x = q.front().first ;
            long long int y = q.front().second ;
            
            q.pop(); 
            
            cout<<x<<" "<<y<<endl;
            
            if( x+ 1 < n  && y<m)
            {
                if( ans[x+ 1][y] >= ans[x][y] + 1) 
                {
                    ans[x+ 1][y] = ans[x][y] + 1;
                    q.push( {x+ 1, y} ) ;
                } 
            }
            if( x-1 >=0  && y<m)
            {
                if( ans[x-1][y] >= ans[x][y] + 1)
                {
                    ans[x-1][y] = ans[x][y] + 1;
                    q.push({x-1, y}) ;
                } 
            }
            if( x < n && y-1>=0)
            {
                if( ans[x][y-1] >= ans[x][y]+ 1 )
                {
                     ans[x][y-1] = ans[x][y]+ 1;
                    q.push({x, y-1}) ;
                } 
            }
            if( x<n && y+1 <m )
            {
                if( ans[x][y+1] >= ans[x][y] + 1)
                {
                     ans[x][y+1] = ans[x][y] + 1; 
                    q.push( {x, y+ 1}) ;
                } 
            }
            
        }
        
        for( int i= 0 ;i<n ; i++)
        {
            for( int j= 0 ; j<m ; j++) cout<<ans[i][j]<<" ";
            cout<<endl;
        }
        
        long long int max_dist = 0 ;
        
        for( int i= 0 ; i<n ; i++)
        {
            for( int j = 0 ; j<m ; j++)
            {
                if( max_dist < ans[i][j] ) max_dist = ans[i][j] ;
            }
        }
        return max_dist== INT_MAX ? -1 : max_dist ;
    }
};