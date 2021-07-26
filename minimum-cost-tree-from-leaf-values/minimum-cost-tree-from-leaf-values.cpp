class Solution {
public:
    
    int rec( int start , int end , vector<int>& arr, vector<vector<int>>&t )
    {
        if( start >= end) return t[start][end] = 0;
        
        if( t[start][end] != -1) return t[start][end] ; 
        
        int ans = INT_MAX ;
        for( int k = start ; k<end ; k++)
        {
            int first = rec( start , k , arr, t) ;
            int second = rec( k+ 1, end , arr, t) ;
            
            int maxi_first = *max_element(arr.begin()+ start, arr.begin()+ k+ 1) ;
            int maxi_second = *max_element(arr.begin()+ k+ 1, arr.begin()+ end+ 1) ;
            
            int temp = first + second + maxi_first* maxi_second;
            
            ans = min( ans , temp) ;
        }
        return t[start][end] = ans ;
    }
    
    int mctFromLeafValues(vector<int>& arr) 
    {
        //MCM so we use recursion but that is Bruit force
        // i, j, k o(n3) , this Q can be done with stack in O(n) 
        // dp[i, j] = dp[i, k] + dp[k + 1, j] + max(A[i, k]) * max(A[k + 1, j])
        
        int n = arr.size() ;
        vector<vector<int>>t(n+ 1, vector<int>( n+ 1, -1) ) ;
        
        return rec( 0 , n-1, arr, t) ;
    }
};