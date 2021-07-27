class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size() ;
        int m = matrix[0].size() ; 
        
        vector<vector<int>>t(n, vector<int>( m, 0) ) ;
        
        for( int j = 0 ; j<m ; j++ )
        {
            t[0][j] = matrix[0][j] ;
        }
        
        for( int i= 1; i<n ; i++)
        {
            for( int j= 0 ; j<m ; j++)
            {
                if( j-1 >=0 && j+ 1< m)
                    t[i][j] = min( { t[i-1][j-1] , t[i-1][j] , t[i-1][j+1] }) + matrix[i][j] ;
                
                else if(j-1 >=0 )
                    t[i][j] = min( t[i-1][j-1] , t[i-1][j] ) + matrix[i][j] ;
                
                else if( j+ 1 <m)
                    t[i][j] = min( t[i-1][j] , t[i-1][j+ 1] ) + matrix[i][j] ;
            }
        }
        return *min_element( t[n-1].begin() , t[n-1].end() ) ;
    }
};