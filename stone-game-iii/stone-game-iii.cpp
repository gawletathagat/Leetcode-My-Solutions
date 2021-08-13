class Solution {
public:
    
    vector<int>t ;
    
    int rec( int i , vector<int>&s )
    {
        if( i >= s.size() ) return  0 ;
        
        if( t[i] != -1) return t[i] ;
        
        int ans = INT_MIN ;
        
        //sum = Alice - Bob + Alice - Bob   ==  total Alice pick - total Bob Pick
        
        if( i <s.size() )
         ans = max( ans , s[i] - rec( i+ 1, s) ) ;
        
        if( i+ 1 < s.size())
        ans = max( ans , s[i] + s[i+ 1] -  rec(i+ 2, s ))  ;
        
        if( i+ 2 < s.size() )
        ans = max( ans , s[i] + s[i+ 1] + s[i+ 2] - rec( i+ 3, s) ) ;
        
        return t[i] = ans ;
    }
    
    string stoneGameIII(vector<int>& s)
    {
        // we try to check every case 
        //case- 1 when we pick only 1 stone 
        // case- 2 pick 2 stones 
        // case - 3 pick 3 stones
        
        // sum = Alice - Bob + Alice - Bob   ==  total Alice pick - total Bob Pick 
        
        t.resize(s.size() + 1, -1 ) ;
        
       int sum =  rec(0 , s) ;
      
        if( sum > 0 ) return "Alice" ;
        if( sum == 0) return "Tie" ;
         
        return "Bob" ;
    }
};