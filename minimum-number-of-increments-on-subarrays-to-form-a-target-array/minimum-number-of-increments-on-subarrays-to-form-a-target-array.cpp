class Solution {
public:
    int minNumberOperations(vector<int>& nums)
    {
        // initally sum is nums[0] ;
        // if nums[i] > nums[i-1] --> sum = sum + nums[i]- nums[i-1] ;
        
        int sum = nums[0] ;
        
        for( int i= 1 ; i<nums.size() ; i++)
        {
            if( nums[i] > nums[i-1] )
            {
                sum = sum + nums[i]- nums[i-1] ;
            }
        }
        
        return sum ;
        
    }
};