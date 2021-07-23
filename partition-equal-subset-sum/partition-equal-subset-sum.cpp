class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        // knapsack problem 
        int total = accumulate( nums.begin() , nums.end(), 0 ) ;
        if( total %2 != 0) return false;
        
        total = total/2 ;
        int n = nums.size() ;
        vector<vector<bool>>t(n+ 1, vector<bool>( total+ 1 , false) ) ; //
        t[0][0] = true;
        
        for( int i= 1 ; i<n+ 1 ; i++)
        {
            for( int j= 1 ; j<total+ 1 ; j++)
            {
                if( j >= nums[i-1] )
                {
                    t[i][j] = t[i-1][j] || t[i-1][j-nums[i-1]] ;
                }
                else 
                    t[i][j] = t[i-1][j] ;
            }
        }
        
        return t[n][total] ;
        
        
    }
};