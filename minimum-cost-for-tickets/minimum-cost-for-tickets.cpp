class Solution {
public:
    
    int rec( vector<int>&days, vector<int>&costs, int i, vector<int>&dp )
    {
        if( i== days.size() ) return 0;
        if( dp[i] != -1) return dp[i] ;
        
        int choice1 = costs[0] ;
        choice1 = choice1 + rec( days, costs, i+ 1, dp) ;
        
        int choice2 = costs[1] ;
        int j = i ;
        while( j<days.size() && days[j]- days[i] < 7) j++;
        
        choice2 = choice2 + rec( days, costs, j , dp) ;
        
        
        int choice3 = costs[2] ;
        j = i ;
        while( j<days.size() && days[j] - days[i] < 30) j++;
        
        choice3 = choice3 + rec( days, costs, j, dp) ;
        
        return dp[i] = min({choice1, choice2, choice3} ) ;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
       vector<int>dp(366,-1) ;
        
        return rec( days, costs, 0, dp) ;
    }
};