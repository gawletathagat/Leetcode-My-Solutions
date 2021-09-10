class Solution {
public:
    
    int dp[366];
    
    int rec( int i , vector<int>&days , vector<int>&costs )
    {
        int n = days.size() ;
        
        if( i == days.size() ) return 0 ;
         if( dp[i] != -1) return dp[i] ;
        
        int choice_1 = costs[0] + rec( i+ 1, days, costs) ;
        
        int choice_2 = costs[1] ;
        int j = i ;
        while(j<n && days[j] - days[i] < 7 ) j++;
        choice_2 = choice_2 + rec( j , days, costs ) ;
        
        int choice_3 = costs[2] ;
         j = i ;
        while( j<n && days[j] - days[i] <30) j++;
        choice_3 = choice_3 + rec( j, days, costs) ;
        
        return dp[i] = min({ choice_1, choice_2 , choice_3 } ) ;
        
    }
    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        
      memset(dp, -1, sizeof(dp) ) ;
        
        sort( days.begin() , days.end() ) ;
        return rec( 0, days, costs) ;
    }
};