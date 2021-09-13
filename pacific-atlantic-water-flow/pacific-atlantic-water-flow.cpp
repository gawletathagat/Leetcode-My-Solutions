class Solution {
public:
    
    void dfs( int i, int j, int prev, vector<vector<int>>&nums, vector<vector<int>>&ocean)
    {
        if( i<0 || i>= nums.size() || j<0 || j>= nums[0].size() || ocean[i][j] == 1 || prev>nums[i][j] ) return ;
        ocean[i][j] =1 ;
        
        dfs( i+ 1, j, nums[i][j] , nums, ocean) ;
         dfs( i, j+ 1, nums[i][j] , nums, ocean) ;
        dfs( i-1, j, nums[i][j] , nums, ocean) ;
        dfs( i, j-1, nums[i][j] , nums, ocean) ;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& nums)
    {
        int n = nums.size() ;
        int m = nums[0].size() ;
        
        if( n== 0 || m== 0 ) return {} ;
        
        vector<vector<int>>p( n+ 1,vector<int>(m+ 1, 0) ) ;
        vector<vector<int>>a( n+ 1, vector<int>( m+ 1, 0)) ;
        
        
        // dfs
        for( int i= 0 ;i<n ; i++)
        {
            dfs( i , 0, INT_MIN , nums, p) ;
            dfs( i, m-1,INT_MIN, nums, a) ;
        }
        for( int j= 0 ; j<m  ; j++)
        {
            dfs( 0, j , INT_MIN, nums, p) ;
            dfs( n-1, j, INT_MIN, nums, a) ;
        }
         
       // ans  
        vector<vector<int>>ans ;
        for( int i= 0 ; i<n; i++)
        {
            for( int j= 0 ;j<m ; j++)
            {
                if( p[i][j] == 1 && a[i][j] == 1)
                {
                    ans.push_back({i,j}) ;
                }
            }
        }
        return ans ;
    }
};