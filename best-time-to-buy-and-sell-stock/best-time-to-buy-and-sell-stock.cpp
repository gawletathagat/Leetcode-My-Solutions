class Solution {
public:
    int maxProfit(vector<int>& nums)
    {
        int buy = INT_MAX ;
        int sell = INT_MIN ;
        int max_sell = INT_MIN ;
        for( int i= 0;i<nums.size() ; i++)
        {
            if( nums[i] < buy )buy = nums[i] ;
            else 
            {
                sell = nums[i] - buy ; 
                max_sell = max( max_sell , sell) ;
            }
        }
        max_sell = max( max_sell , sell) ;
        
        return max_sell!= INT_MIN ? max_sell : 0 ;
    }
};