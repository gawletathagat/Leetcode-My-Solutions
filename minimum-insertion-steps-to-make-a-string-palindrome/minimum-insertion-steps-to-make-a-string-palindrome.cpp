class Solution {
public:
    
    
    int rec( string& s, int start, int end, vector<vector<int>>&dp )
    {
        if( start >= end ) return 0;
        
        if( dp[start][end] != -1) return dp[start][end] ;
        
        if( s[start] == s[end] )
        {
            return dp[start][end]= rec( s, start+ 1, end-1, dp) ;
        }
        else 
        {
            return dp[start][end]= 1+ min( rec(s,start+ 1, end, dp) , rec( s, start, end-1, dp)) ; 
        }
    }
    
    int minInsertions(string s)
    {
        if( s.size() <=1) return 0 ;
        vector<vector<int>>dp( s.size() , vector<int>(s.size(), -1) ) ;
        
       return rec( s, 0, s.size()-1, dp) ;
    }
};