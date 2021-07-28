class Solution {
public:
    int maxProfit(vector<int>& price)
    {
        if(price.size() == 0) return 0;
        
        long  buy = INT_MAX ;
        long  maxi = 0 ;
       
        
        for( int i= 0; i<price.size() ; i++)
        {
            if( buy > price[i] )
            {
                buy = price[i] ;
            }
            else // buy< price[i]
            {
                long profit = price[i]- buy ;
                
                maxi = max( maxi , profit ) ;
            }
        }
        
        return maxi ;
        
    }
};