class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& nums) 
    {
        int n= nums.size() ;
        int m = nums[0].size() ;
        
        vector<vector<int>>t( n+ 1, vector<int>(m+ 1, INT_MAX )) ;
        
        t[n-1][m]= 1;
        t[n][m-1] = 1;
        
        for( int i= n-1; i>=0; i--)
        {
            for( int j= m-1; j>=0 ; j--)
            {
                int val = min( t[i+1][j] , t[i][j+1] ) - nums[i][j] ;
                
                t[i][j] = max( 1, val ) ;
            }
        }
        
        return t[0][0] ;
        
    }
};