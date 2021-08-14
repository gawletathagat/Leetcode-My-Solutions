class Solution {
public:
    
    vector<vector<int>>t;
    
    int rec( int start , int end , vector<int>&nums) 
    {
        if( start > end ) return  0 ;
        if( start == end) return 0 ; //  only one element is left so we have to remove the max part and choose the least part se we took 0
        
        if( t[start][end] != -1) return t[start][end ];
        
        int right = 0 ;  // initally right sum is total sum from start to end 
        for( int i = start ; i<= end ; i++)
        {
            right = right + nums[i] ;
        }
        
        // now we have to split 
        int ans = 0 ;
        int left = 0 ;
        for( int i= start ; i<= end ; i++)
        {
            left = left + nums[i] ;  //   6 | 2,3,4,5,5
            
            right = right - nums[i] ;
            
            if( left < right)  // we have to add left part 
            {
                ans = max( ans , left + rec(start , i, nums ) ) ;
            }
            else if( left == right)  // we let alice decive which part she want 
            {
                ans = max({ ans , left+ rec( start , i , nums)  , right + rec( i+ 1, end, nums) });
            }
            else if( left > right) 
            {
                ans = max( ans , right + rec( i+ 1, end , nums) ) ;
            }
        }
        
        return t[start][end] = ans ;
    }
    
    int stoneGameV(vector<int>& nums)
    {
        //[6,2,3,4,5,5]
        int n = nums.size() ;
        if( n<= 1) return 0;
        
        t.resize( n+ 1, vector<int>( n+ 1, -1) ) ;
        
        return rec( 0 , n-1 , nums ) ;
    }
};