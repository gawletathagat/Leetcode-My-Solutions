class Solution {
public:
    int maxProfit(vector<int>& p, int fee) 
    {
        int n = p.size() ;
        
        vector<int>buy_profit(n, 0 );
        vector<int>sold_profit( n, 0) ;
        
        buy_profit[0] = - p[0];
        
        for( int i= 1; i<n ; i++)
        {
            buy_profit[i] = max( buy_profit[i-1] , sold_profit[i-1] - p[i] ) ;
            
            sold_profit[i] = max( sold_profit[i-1] , buy_profit[i-1]+ p[i]- fee) ;
        }
        
        return sold_profit[n-1 ] ;
        
    }
};