class Solution {
public:
    int dp[101][10005] ;
    int rec( int k , int n)
    {
        if( n==1 || n==0 ) return n ;
        if( k ==1 ) return n;
        
        if( dp[k][n] != -1) return dp[k][n] ;
        
        int ans = INT_MAX ;
        int start = 1, end = n ;
       while(start<=end)
        {
           int i = start + (end-start)/2 ;
            int low = 0, heigh = 0;
            if( dp[k-1][i-1] != -1) low = dp[k-1][i-1] ;
            else
            {
                low = rec( k-1,i-1); 
                dp[k-1][i-1] = low ;
            }
            
            if( dp[k][n-i] != -1) heigh = dp[k][n-i] ;
            else
            {
                heigh = rec( k, n-i) ;
                dp[k][n-i] = heigh ;
            }
           
           if( low < heigh) start = i+ 1;
           else end = i-1;
            
            int temp_ans = 1+ max( low, heigh ) ;  // max -> worst case
            ans = min( ans , temp_ans) ;          // min opoerations
        }
        return dp[k][n] = ans ;
    }
    
    int superEggDrop(int k, int n)
    {
        //this Q has 4 solutions
        //sol-1 rec
        // n= number of floors
        memset(dp, -1, sizeof(dp)) ;
        return rec( k , n) ;
    }
};