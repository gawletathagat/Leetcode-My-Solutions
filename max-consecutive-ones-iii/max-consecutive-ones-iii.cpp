class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int i= 0 ;
        int j = 0 ;
        
        int max_len = INT_MIN ;
        int one_count =  0;
        while( j< nums.size() )
        {
            if( nums[j]== 0) one_count++;
            
            while(one_count > k  )
            {
                if( nums[i] == 0) one_count-- ;
                i++;
            }
            
            max_len = max( max_len , j-i+ 1) ; 
            j++;
        }
        
        return max_len== INT_MIN ? 0 : max_len ;
    }
};