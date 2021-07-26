class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        // unbounded knapsack , coins change 2, 1 <= nums.length <= 200 on O(n2) will work  200*200 < 10^8
        long long int n = nums.size();
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        
        for(long long int j =0; j<target+1; j++){
            for(long long int i=0; i<n; i++){
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