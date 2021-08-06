class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> dp(s.size()+1,0);
        dp[0] = 1;
        for(int i=1;i<dp.size();i++)
        {
            dp[i] = (dp[i-1])*2%1000000007;
            for(int j = i-1;j>0;j--)
            {
                if(s[i-1] == s[j-1])
                {
                    dp[i] = (dp[i] - (dp[j-1]))%1000000007;
                    break;
                }
            }
        }
        if(dp[s.size()] < 0)
            dp[s.size()] += 1000000007;
        return (dp[s.size()]-1);   // minus 1 for non empty
    }
};