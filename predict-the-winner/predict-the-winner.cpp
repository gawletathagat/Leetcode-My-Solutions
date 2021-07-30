class Solution {
public:
    int func(int i, int j, vector<vector<int>> &dp, vector<int> &a){
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=max(
            a[i]+min(func(i+2,j,dp,a),
                     func(i+1,j-1,dp,a)
                    ),
            a[j]+min(func(i,j-2,dp,a),
                     func(i+1,j-1,dp,a)
                    )
        );
    }
    bool PredictTheWinner(vector<int>& a){
      int sum=0, n=a.size();
      for(auto el:a)
          sum+=el;
      vector<vector<int>> dp(n, vector<int>(n,-1));  
      int val=func(0,n-1,dp,a);
      return val>=(sum-val);
    }
};