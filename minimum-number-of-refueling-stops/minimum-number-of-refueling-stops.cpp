class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
//         dp[i][j] = our curr reach 
        
//         i == total fuelpoint 
//         j == fuel point we Refuel
//         case-1 : we didn't stop at this point 
//         case-2 : we stop at this point  
        int n = stations.size() ;
        
        vector<vector<long long int>>dp( n+ 1, vector<long long int>(n+ 1, 0 ) ) ;
            
        for( int i=  0 ; i<n+1 ; i++)
        {
            dp[i][0] = startFuel ;  // we didn't stop at any point
        }
        
        for( int i= 1; i< n+ 1; i++)
        {
            for( int j= 1; j<=i; j++)
            {
                dp[i][j] = dp[i-1][j] ;  // we didn't stop at this point j value not change
                
                if( dp[i-1][j-1] >= stations[i-1][0] ) 
                {
                    dp[i][j] = max( dp[i][j] , dp[i-1][j-1] + stations[i-1][1] ) ;
                }
            }
        }
        
        for( int j= 0; j<n+1 ; j++)
        {
            if( dp[n][j] >= target) return j ;
        }
        return -1;
        
    }
};