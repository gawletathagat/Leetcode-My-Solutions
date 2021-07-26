class Solution {
public:
    int numSquares(int n) 
    {
        int t[n+ 1] ;
    
        for( int i= 0; i<n+ 1; i++) t[i] = i;
        
     //   t[0] = 0 ;
        
        for( int i= 1 ; i<=n ; i++)
        {
           // t[i] = i ;
            
            for( int j = 1; j*j<=i ; j++)
            {
                if( i >= j*j )
                t[i] = min( t[i] , 1+ t[i-j*j] ) ;
            }
        }
        
        return t[n] ;
        
    }
};