class Solution {
public: 
    int totalHammingDistance(vector<int>& nums)
    {       
       int ans = 0;
        // since every integer is made with  
        // 32 bits
        int n = nums.size() ;
        for( int i= 0  ; i<32 ; i++)
        {
            int ones_bit = 0 ;
            // for( int j= 0 ;j<nums.size() ; j++)
            // {
            //     ones_bit = ones_bit + (nums[j] >> i)& 1  ;
            // }
            for (auto num: nums) ones_bit +=  (num >> i) & 1;
            
           ans = ans +  ones_bit * (nums.size() - ones_bit);
        }
        return ans ;
    }
};