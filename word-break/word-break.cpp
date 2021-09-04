class Solution {
public:
    
    vector<int>dp;
    
    bool rec( int start,unordered_set<string>&st , string& s )
    {
        if( start == s.size() ) return true ;
        
        if( dp[start] != -1 ) return dp[start] ;
        
        for( int i= start+ 1 ; i<=s.size() ; i++)
        {
            string temp = s.substr( start , i- start ) ;
            
            if( st.find(temp) != st.end() ) 
            {
                if( rec( i, st, s) ) return dp[start] = true;
            }
        }
        return dp[start] = false; 
    }
    
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string>st(wordDict.begin() , wordDict.end() );
        
        dp.resize( s.size()+ 1, -1) ;
        
        return rec( 0, st, s) ;
    }
};