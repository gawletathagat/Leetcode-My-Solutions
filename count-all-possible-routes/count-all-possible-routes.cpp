class Solution {
public:
     int mod=(1e9+7);
     vector<vector<int>>dp ;
    int rec( vector<int>&nums , int start , int finish , int fuel)
    {
        if( start<0 || start>=nums.size() || fuel<0) return 0 ;
        
        int ans =0;
        if( start == finish ) ans = 1;
        
        if( dp[start][fuel] != -1) return dp[start][fuel ]; 
        
        for( int i= 0 ; i<nums.size() ; i++)
        {
            if( i!= start) 
            ans = ans + rec( nums, i, finish , fuel - abs(nums[start] - nums[i] ) ) ; 
            ans = ans%mod ;
        }
        
        return dp[start][fuel] = ans ;
    }
    
    int countRoutes(vector<int>& nums, int start, int finish, int fuel) 
    {
        dp.resize(205 , vector<int>(205, -1) ) ;
        return rec( nums, start, finish , fuel) ;
    }
};