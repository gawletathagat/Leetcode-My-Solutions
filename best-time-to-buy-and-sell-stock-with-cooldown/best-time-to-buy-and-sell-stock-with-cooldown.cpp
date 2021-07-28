class Solution {
public:
    int maxProfit(vector<int>& p)
    {
       // NoStock( Rest) <---Sold
       //  \                / 
       //   \              /
       //    \            /
       //        InHand
        
        int n = p.size() ;
        if( n <= 1) return 0 ;
        
                    
        vector<int>Nostock(n+ 1, 0);   // this all are profits
        vector<int>InHand( n+ 1, 0);
        vector<int>Sold( n+ 1 , 0) ;
        
        Nostock[0] = 0 ;
        InHand[0] = -p[0] ;
        Sold[0] = INT_MIN ;
        
        for( int i= 1; i<n ; i++)
        {
            Nostock[i] = max( Nostock[i-1] , Sold[i-1] ) ;
            
            InHand[i] = max( InHand[i-1] , Nostock[i-1] - p[i] ) ;
            
            Sold[i] = InHand[i] + p[i] ;
        }
        
        return max( Sold[n-1] , Nostock[n-1] );
        
        
    }
};