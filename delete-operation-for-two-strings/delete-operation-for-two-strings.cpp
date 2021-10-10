class Solution {
public:
    int minDistance(string s1, string s2) 
    {
        // lcs 
        // ans = s1- lcs + s2- lcs 
        
        int n = s1.size() ;
        int m = s2.size() ;
        vector<vector<int>>dp(n+ 1, vector<int>(m+ 1, -1) ) ;
        
        for( int i= 0 ; i<n+ 1; i++) dp[i][0] = 0 ;
        for( int j= 0 ; j<m+ 1; j++) dp[0][j] = 0 ;
        
        
        for( int i= 1; i<n+ 1; i++)
        {
            for(int j= 1; j<m+ 1; j++)
            {
                if( s1[i-1] == s2[j-1] )
                {
                    dp[i][j] = 1+ dp[i-1][j-1] ;
                }
                else 
                {
                    dp[i][j] = max( dp[i-1][j] , dp[i][j-1] ) ;
                }
            }
        }
        cout<<dp[n][m] ;  // lcs
        return n- dp[n][m] + m - dp[n][m] ;
        
    }
};