class Solution {
public:
    int maximalSquare(vector<vector<char>>& nums) 
    {
        int n = nums.size() ;
        int m = nums[0].size() ;
        
        vector<vector<int>>t(n+ 1, vector<int>(m+ 1, 0) ) ;
        
        for( int i= 0 ; i<n ; i++)
            t[i][0] = nums[i][0]-'0' ;
        
        for( int j= 0 ; j<m; j++)
        {
            t[0][j] = nums[0][j]-'0' ;
        }
        
        for( int i= 1; i<n; i++)
        {
            for( int j = 1; j<m; j++)
            {
                if( nums[i][j] != '0')
                t[i][j] = min({ t[i-1][j] , t[i][j-1] , t[i-1][j-1]}) + 1 ;
            }
        }
        
        int maxi = 0 ;
        for( int i= 0 ; i<n; i++)
        {
            for( int j = 0 ; j<m ; j++)
            {
                if( maxi < t[i][j] ) maxi = t[i][j] ;
            }
        }
        
        return maxi*maxi;
    }
};