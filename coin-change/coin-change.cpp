class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        // unbounded Knapsack
        int n = coins.size() ;
        int m = amount ;
        
        // Always use long long int 
        
        vector<vector<long long int>>t(n+ 1, vector<long long int>(amount+ 1, 0) ) ;
 
       for( int i= 0; i<n+1 ; i++) t[i][0] = 0 ;
        for( int j= 1 ; j<amount+ 1 ; j++) t[0][j] = INT_MAX;
        
         for( int i= 1; i<n+1 ; i++)   // coins
        {
            for( int j = 1; j<amount+ 1 ; j++)   // amount
            {
              if (coins[i - 1] <= j)
               t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
                else
                {
                    t[i][j] = t[i-1][j] ;
                }
            }
        }
        
        if( t[n][m] == INT_MAX) return -1;
        return t[n][m] ;
        
    }
};