class Solution {
public:
    int mod = 1e9+ 7 ;
    int dp[5002][10] ;
     vector<vector<int>> moves = {{4, 6}, {8, 6}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
    
    int rec( int i , int n)
    {
        if(n==0) return 1;
        
        if( dp[n][i] != -1) return dp[n][i] ;
        
        long long int sum = 0;
        
       for( int j = 0 ; j<moves[i].size() ; j++)
       {
           sum  = sum + rec( moves[i][j] , n-1) ;
       }
        
        return dp[n][i] = sum%mod  ;
    }
    
    int knightDialer(int n) 
    {
        long long ans = 0;
        memset(dp, -1, sizeof(dp));
        
        for( int i= 0 ; i<10 ; i++)
        {
            ans = ans + rec( i , n-1)  ;
        }
        return ans%mod;
    }
};