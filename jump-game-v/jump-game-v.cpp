class Solution {
public:
    
    vector<int>dp ;
    
    int rec( int i , vector<int>&arr, int d)
    {
        if( i<0 || i>= arr.size() ) return 0;
        
        if( dp[i] != -1) return dp[i] ;
        
        int ans = 1;
        int n = arr.size() ;
        int low = max(i-d ,0) ;
        int high =min( i+d , n-1) ;
        
        for( int j = i-1 ; j>=low ; j--)
        {
            if( arr[j] >= arr[i] ) break;
            ans = max( ans , 1+ rec( j , arr, d)) ;
        }
        
        for( int j= i+ 1; j<=high ;j++)
        {
            if( arr[j] >= arr[i] ) break;
            ans = max( ans , 1+ rec( j , arr, d) ) ;
        }
        
         return dp[i] = ans ;
    }
    
    int maxJumps(vector<int>& arr, int d)
    {
        
        dp.resize( arr.size() , -1) ;
        
        int max_jump = 0;
        for( int i= 0; i<arr.size() ; i++)
        {
            int jump = rec( i, arr,d ) ;
            max_jump = max( max_jump, jump ) ;
        }
            
        return max_jump ;
    }
};