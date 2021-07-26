class Solution {
public:
    int change(int target, vector<int>& nums)
    {
        // unbounded Knapsack tc -O(n2) alwasys see the constrains 1 <= coins.length <= 300 
//        int dp[amount + 1];
        
//         memset(dp,0,sizeof(dp));
        
//         dp[0] = 1;
        
//         for (const auto & c : coins) 
//             for (int i = 0; i <= amount; ++i) 
//                {
//                 if(i-c >= 0 )
//                    dp[i] += dp[i - c]; 
                
//                }   
        
//         return dp[amount];
        long long int n = nums.size();
        
        int dp[target+1];
        
        memset(dp,0,sizeof(dp));
        
        dp[0] = 1;
        
        for(long long int i=0; i<n; i++)
        {
            for(long long int j =0; j<target+1; j++)
            {
                 if(j>=nums[i])
                     dp[j] += dp[j-nums[i]];
            }
            // for(int k=0;k<target+1; k++)
            //     cout<<dp[k]<<" ";
            // cout<<endl;
        }
        return dp[target];
    }
};