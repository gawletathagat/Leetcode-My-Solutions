class Solution {
public:
    
    vector<long long int >t ;
    
    bool rec(  int n)
    {
        if( n <= 0) return t[n] = 0;
        
        if( t[n] != -1) return t[n] ;
        
        for( int i = 1 ; i*i<=n ; i++)
        {
            if( n >=i*i ) 
            {
                t[n-i*i ] = rec( n- i*i ) ;
                
                if(t[n-i*i ] == false ) return true; 
            }
        }
        
        return t[n] = false;
        
    }
    
    bool winnerSquareGame(int n) 
    {
//         for( int i = 1 ; i<n ; i++ )
//         {
//             v.push_back( i*i ) ;
//         }
        
        t.resize(n+ 1, -1) ;
        
        if( n == 1) return true;
        
        return rec( n) ;
        
        // if( sqrt(n) * sqrt(n) == n ) return true; 
        // return false;
        
    }
};