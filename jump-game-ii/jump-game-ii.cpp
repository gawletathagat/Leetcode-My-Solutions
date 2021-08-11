class Solution {
public:
    int jump(vector<int>& nums)
    {
        // mum number of jumps means every time we have to go max 
        
        // 2 solutions Dp , greedy 
        // DP
        vector<int>t( nums.size() , INT_MAX) ;
        
        t[0] = 0 ;
        
        for( int i= 1 ; i<nums.size() ; i++)
        {
            for( int j = 0 ; j<i ; j++)
            {
                if(t[j] != INT_MAX && j+nums[j] >= i )
                {
                    t[i] = min( t[i] , t[j] + 1) ;
                }
            }
        }
        
        return t[nums.size()-1] ;
        
    }
};