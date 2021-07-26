class Solution {
public:
    int minScoreTriangulation(vector<int>& A) 
    {
        //MCM formate , dont think logicly think in the MCM way we doest know which 3 point 
        //so are going to choose all the combinations of 3 points and this formate is MCM   
        //Constrains 3 <= n <= 50 that means will go something like O(n4) or 2^n
        
        // In MCM we think only recursively.
        
        // 3 loops n-2 triangles
       int n = A.size();        
		vector<vector<int>>dp(n, vector<int>(n, 0));

		for (int L = 2; L <= n; L++) {
			for (int i = 0; i+L < n; i++) {
				int j = i+L;
				dp[i][j] = INT_MAX;
				for (int k = i+1; k < j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i]*A[k]*A[j]);
				}
			}
		}

		return dp[0][n-1];
        
    }
};