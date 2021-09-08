class Solution {
public:
    
    int rec( vector<int>&prices, vector<vector<int>>&dp , int fee, int i, bool can_sell )
    {
        if( i == prices.size() )return 0 ;
        
        if( dp[can_sell][i] != -1) return dp[can_sell][i] ;
        
        if( can_sell == false)  // time to buy 
        {
            dp[can_sell][i] = max( rec(prices,dp,fee,i+1,true)-prices[i]  , rec(prices,dp,fee,i+1,false) ) ;
        }
        if( can_sell == true)  //time to sell
        {
            dp[can_sell][i] = max( rec(prices,dp,fee,i+1,false)+prices[i]-fee , rec(prices,dp,fee,i+1,true)) ; 
        }
        
        return dp[can_sell][i] ;
    }
    
    int maxProfit(vector<int>& prices, int fee)
    {
        // brute force -> just to understarnd the constrains 
        int n = prices.size() ;
        vector<vector<int>>dp(2, vector<int>(n, -1) ) ;
        
        return rec( prices, dp, fee, 0, false) ;   
    }
};