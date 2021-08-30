class Solution {
public:
    int countVowelPermutation(int n)
    {
        int mod = 1e9  + 7;
        vector<vector<long long>> dp(n+1,vector<long long>(5,0));
        
        for(int i=0;i<5;i++)
            dp[1][i] = 1;
        
        for(int i=1;i<n;i++){
            //if char was 'a'
            dp[i+1][0] = (dp[i][1] + dp[i][2] + dp[i][4])%mod;
            
            //if char was 'e'
            dp[i+1][1] = (dp[i][0] + dp[i][2])%mod;
            
            //if char was 'i'
            dp[i+1][2] = (dp[i][1] + dp[i][3])%mod;
            
            //if char was 'o'
            dp[i+1][3] = (dp[i][2])%mod;
            
            //if char was 'u'
            dp[i+1][4] = (dp[i][2] + dp[i][3])%mod;
        }
        
        int res = 0;
        for(auto x : dp.back())
        {
            
            res += x;
            res %= mod;
        }
        
        return res;
    }
};