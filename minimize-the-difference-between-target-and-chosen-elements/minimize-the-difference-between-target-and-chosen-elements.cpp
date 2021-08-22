class Solution {
public:
  
    int t[10000][79];
    int rec( int i, int sum, vector<vector<int>>&mat, int target) 
    {
        if( i>= mat.size() ) return abs(sum - target ) ;
        
        if( t[sum][i] != -1) return t[sum][i] ;
        
        int ans = INT_MAX ;
        
        for( int j = 0 ; j<mat[0].size() ; j++)
        {
            ans = min( ans , rec( i+ 1, sum+ mat[i][j] , mat, target) ) ;
        }
         
        return t[sum][i] = ans;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) 
    {
        // DP , and backtracking  
        
        memset(t, -1, sizeof(t)) ;
        
       return  rec( 0 ,0, mat, target) ;
        
    }
};