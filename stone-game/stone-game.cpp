class Solution {
public:
    
    vector<vector<int>>t ;
    
    int rec( int start , int end , vector<int>&p )
    {
        if( start > end ) return 0 ;
          
        if( t[start][end] != -1) return t[start][end ];
        
        int front = p[start]  - rec( start + 1, end,  p );
        int back =  p[end]    - rec( start , end- 1 , p ) ;
        
        return t[start][end] = max( front , back ) ;
    }
    
    bool stoneGame(vector<int>& p) 
    {
         // Alice - Bob + Alice - Bob 
        
        // sum = max sum of alice that she can acchive  - max sum of bob that he can acchive
        
        t.resize( p.size() + 1, vector<int>( p.size()+ 1, -1)) ;
        
        int sum = rec(0 , p.size()-1,  p) ;
        
        return sum > 0  ;
    }
};