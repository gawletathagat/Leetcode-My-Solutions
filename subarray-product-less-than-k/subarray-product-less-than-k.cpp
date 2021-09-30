class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        if( k<=1) return 0;
        
        int i = 0 ; int j = 0 ;
        int count = 0 ;
        int prod = 1;
        
        while( i<nums.size() )
        {
            prod = prod*nums[i] ;
            
            
            while( prod >=k && j<nums.size() )
            {
                prod = prod/nums[j++] ;
            }
            
            count = count + i-j+ 1 ;
            
            i++;
        }
        
        return count;
        
    }
};