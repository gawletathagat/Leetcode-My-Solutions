class Solution {
public:
    int maxProfit(int k, vector<int>& p) 
    {
        int n = p.size() ;
        if( n==0 ) return 0;
         int t[k+ 1][n+ 1] ;
             
        for( int i=0 ; i<k+1; i++) t[i][0] = 0 ;
        for( int j = 0; j<n+ 1; j++) t[0][j] =  0 ;
       
        for( int i= 1; i<k+ 1; i++)
        {
             int prev_profit = INT_MIN ;
            for( int j= 1; j<n ; j++)
            {
                prev_profit = max( prev_profit , t[i-1][j-1] - p[j-1] ) ;
                
                t[i][j] = max( t[i][j-1] , prev_profit + p[j] ) ;
            }
        }
        
        return t[k][n-1] ;
        
    }
};