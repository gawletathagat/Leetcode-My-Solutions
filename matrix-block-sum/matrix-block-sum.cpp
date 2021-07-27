class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) 
    {
        int n = mat.size() ;
        int m = mat[0].size() ;
        
        vector<vector<int>>sum(n+1, vector<int>(m+1, 0) ) ;
        
        for( int i= 1 ; i<n+1 ; i++)
        {
            for( int j = 1 ; j<m+1; j++)
            {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mat[i-1][j-1];
            }
        }
        
        vector<vector<int>>ans( n, vector<int>(m, 0) ) ;
        
        for( int i= 0; i<n; i++)
        {
            for( int j= 0; j<m; j++)
            {
                int Rup = max( 0, i-k) ;
                int Rdown = min( n-1, i+k) ;
                
                int Cleft = max( 0, j-k) ;
                int Cright = min(m-1, j+k ) ;
                
                Rup++; Rdown++;
                Cleft++; Cright++ ;
                
                ans[i][j] = sum[Rdown][Cright] - 
                    ( sum[Rdown][Cleft-1] + sum[Rup-1][Cright] - sum[Rup-1][Cleft-1]);
				
            }
        }
        
        return ans;
        
    }
};