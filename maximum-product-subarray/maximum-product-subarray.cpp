class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int curr_max = 1;
        int curr_min = 1;
        int ans = nums[0];
        
        // think in greedy 
        
        for( int i= 0 ;i<nums.size() ; i++)
        {
            int temp = curr_max ;
            
            curr_max = max({curr_max*nums[i] , curr_min*nums[i] , nums[i]} ) ;
            
            curr_min = min( {temp*nums[i] , curr_min*nums[i] , nums[i]} ) ;
            
            ans= max( ans , curr_max ) ;
        }
        
        return ans  ; 
    }
};