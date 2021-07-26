class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        // unbounded Knapsack tc -O(n2) alwasys see the constrains 1 <= coins.length <= 300 
        int n = coins.size() ;
        int m = amount ;
        
        vector<vector<int>>t( n+ 1, vector<int>(m+ 1, 0 ) ) ;
        
        for( int i= 0 ; i<n+ 1 ; i++) t[i][0]= 1;
        for( int j= 0 ; j<m+ 1; j++) t[0][j] = 0 ;
        
        for( int i= 1; i<n+ 1; i++)
        {
            for( int j= 1; j<m+ 1; j++)
            {
                if( j >= coins[i-1] )
                {
                    t[i][j] = t[i-1][j] + t[i][j-coins[i-1]] ;
                }
                else 
                {
                    t[i][j] = t[i-1][j] ;
                }
            }
        }
        
        return t[n][m] ;    
    }
};