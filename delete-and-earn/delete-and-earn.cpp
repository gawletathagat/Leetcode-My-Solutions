class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        sort( nums.begin() , nums.end() ) ;
        
        int n = nums.size() ;
        vector<int>t(nums.begin() , nums.end() ) ;    // points we earn 
        
        for( int i= 1; i<n ; i++)
        {
            for( int j= 0 ; j<i ; j++)
            {
                if( nums[i]- nums[j] != 1 )
                {
                    t[i] = max( t[i] , t[j] + nums[i]);
                }
            }
        }
        
        return *max_element( t.begin() , t.end() ) ;
        
    }
};