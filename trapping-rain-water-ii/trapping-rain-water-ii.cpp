class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) 
    {
        //https://www.youtube.com/watch?v=QvQiQcLCQ4Y
        priority_queue< array<int,3>, vector<array<int,3>>, greater<>> pq;
      //  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> >pq ;
        
         int n = grid.size() ;
        int m = grid[0].size() ;
        
        vector<vector<int>>vis( n+ 1, vector<int>(m+ 1, 0) ) ;
        
        for( int i = 0 ; i<n; i++) 
        {
            pq.push({grid[i][0], i, 0 } ) ;
            pq.push({grid[i][m-1] , i, m-1} ) ;
        }
        
        for( int j= 0 ; j<m ; j++)
        {
            pq.push({grid[0][j] , 0, j} ) ;
            pq.push({grid[n-1][j] ,n-1 , j} ) ;
        }
        
        int vol = 0;
        int min_boundry = 0;
        
        while( !pq.empty() )
        {
            int height = pq.top()[0] ;
            int x = pq.top()[1] ;
            int y = pq.top()[2] ;
            pq.pop() ;
            vis[x][y] = true;
            
            min_boundry = max(min_boundry , height ) ;
            
            int dr[4] = {0,0, -1 , 1} ;
            int dc[4] = { 1, -1, 0, 0} ;
            
            for( int i= 0 ; i<4 ; i++)
            {
               int xx = x + dr[i] ;
               int yy = y + dc[i] ;
                
                if( xx>=0 && xx<n && yy >=0 && yy<m && vis[xx][yy] == false  )
                {
                    pq.push({grid[xx][yy] , xx, yy} ) ;
                    vis[xx][yy] = true; 
                    
                    if( grid[xx][yy] < min_boundry ) 
                    {
                        vol = vol + min_boundry - grid[xx][yy] ;
                    }
                }
            }
            
            
        }
        
        return vol ;
    }
};