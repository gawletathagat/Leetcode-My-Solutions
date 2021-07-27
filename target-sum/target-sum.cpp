class Solution {
public:
    
    int rec( vector<int>& nums, int sum )
    {
        // number of ways to get sum
        int n = nums.size() ;
        vector<vector<int>>t(2, vector<int>( sum + 1 , 0) ) ;
        
        for( int i= 0 ; i<nums.size() ; i++) t[i%2][0] = 1;
        for( int j = 0 ; j<sum + 1; j++) t[0][j] = 0 ;
        
        t[0][0] = 1;
        
        for( int i= 1; i<nums.size()+ 1; i++)
        {
            for( int j= 0; j<sum + 1; j++)
            {
                if( nums[i-1] <= j)
                {
                    t[i%2][j] = t[(i-1)%2][j] + t[(i-1)%2][j-nums[i-1] ] ;
                }
                else 
                    t[i%2][j] = t[(i-1)%2 ][j ] ;
            }
        }
        
        return t[n%2][sum] ;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) 
    {
//          (first_half) - (second_half )  = target 
//          (first_half) + (second_half )  = total 
//         ------------------------------------------
//             first_half = (target + total)/2 ;
        
        // so Question become find the sum first_half in vector , now this is Knapsack
        
        int total = accumulate( nums.begin() , nums.end() ,  0) ;
        
         if( (target+ total)%2 == 1 || total < target ) return 0;
        
        int first_half = (target + total)/2 ;
        
        return rec(nums, first_half ) ;
    }
};