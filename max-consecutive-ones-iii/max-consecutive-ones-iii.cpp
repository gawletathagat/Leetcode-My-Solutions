class Solution {
public:
    int longestOnes(vector<int>& nums, int k)
    {
        
        unordered_map<int,int>mp ;
        for( int i= 0; i<nums.size() ; i++) mp[nums[i]]++;
        
        int j = 0 ;
        int max_len = 0;
        int zero_count= 0;
        int i= 0 ;
        while( i<nums.size() )
        {
            if( nums[i] == 0)
            {
                zero_count++;
            }
            
            while( zero_count > k)
            {
                mp[nums[j]] ;
                
                if( nums[j] == 0) zero_count-- ;
                
                    if( mp[nums[j]] == 0) mp.erase(nums[j]) ;
                
                j++;
            }
            
            max_len = max( max_len , i-j+ 1) ;
            
            i++;
        }
        return max_len ;
        
    }
};