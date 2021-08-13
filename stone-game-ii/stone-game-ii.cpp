class Solution {
public:
    
    vector<vector<int>>t ;
    
    int rec( int i ,int M, vector<int>&p )
    {
        if( i >= p.size() ) return  0 ;
        
        if( t[i][M] != -1) return t[i][M] ;
        
        int presum = 0 ;
        int ans = INT_MIN ;
        for( int x = 0; x<2*M ; x++)
        {
          if( i+ x < p.size() ) presum = presum + p[i+ x] ;   // presum 
                
           ans = max( ans , presum - rec(i + x + 1 , max( M, x+1 )  , p ) ) ;
        }
        
        return t[i][M] = ans ; 
    }
    
    int stoneGameII(vector<int>& p) 
    {
        // presum.resize( p.size() , 0) ;
        // p[0] = p[0] ;
        //for( int i= 1; i<p.size() ; i++) presum[i] = presum[i-1] + p[i] ; 
        int total = accumulate( p.begin() , p.end() , 0 ) ;   // Alice + Bob 
        
        t.resize( p.size() + 1, vector<int>(p.size()+ 1 , -1) );
        
        // diff_sum = Alice - Bob + Alice- Bob
        
        int diff_sum = rec(0 , 1, p ) ;   // Alice - Bob 
        
        
        return (total + diff_sum)/2 ;    
        
    }
};