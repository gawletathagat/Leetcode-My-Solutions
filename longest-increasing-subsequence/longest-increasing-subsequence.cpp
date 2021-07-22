class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int>t(nums.size(), 1) ; // min 1 element
        
        
        for( int i= 0 ; i<nums.size() ; i++)
        {
            for( int j= 0; j<i ; j++)
            {
                if( nums[i] > nums[j] )
                {
                    t[i] = max( t[i] , t[j] + 1);
                }
            }
        }
        
        return *max_element( t.begin() , t.end() ) ;
        
    }
};