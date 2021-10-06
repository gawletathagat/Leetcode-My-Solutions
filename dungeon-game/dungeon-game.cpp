class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& nums)
    {
        int n = nums.size() ;
        int m = nums[0].size() ;
        
        vector<vector<int>>dp(n+ 1, vector<int>(m + 1, INT_MAX ) ) ;
        
        dp[n-1][m] = 1 ;
        dp[n][m-1] = 1 ;
        
       for( int i= n-1; i>=0 ; i--)
       {
           for( int j = m-1; j>=0 ; j--)
           {
               int val = min( dp[i+1][j] , dp[i][j+1] )  - nums[i][j] ;
               
               dp[i][j] = max( 1, val) ;
           }
       }
        
        
        return dp[0][0] ;
    }
};