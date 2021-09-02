class Solution {
public:
    int mod = 1000000007 ;
    
    int left_bound( int start , int end, int i , vector<int>&nums )
    {
        int bound = nums.size()  ;
        while( start <= end)
        {
            int mid = start + (end- start)/2 ;
            
            if( nums[mid] < 2*nums[i] ) start = mid+ 1;
            else 
            {
                bound = mid ;
                end = mid- 1;
            }
        }
        return bound;
    }
    
    int right_bound( int start , int end, int j, vector<int>&nums)
    {
        int bound = j ;
        int n = nums.size(); 
        
        while( start <= end) 
        {
            int mid = start + (end- start)/2 ;
            
            if( nums[mid] > (nums[n-1] + nums[j])/2 ) end = mid- 1;
            else 
            {
                bound  = mid ;
                start = mid+ 1;
            }
        }
        return bound ; 
    }
    
    int waysToSplit(vector<int>& nums)
    {
        //      [1,2,2,2,5,0]
       //psum //[1,3,5,7,12,12]  
        
        for( int i= 1 ; i<nums.size() ; i++)
        {
            nums[i] = nums[i-1]+ nums[i] ;
        }
        int n = nums.size() ;
        int ans=0 ;
        for( int i= 0 ; i<nums.size()-2 ;i++)
        {
           int left_side =  left_bound(i+ 1, n-2, i , nums ) ;
            
           int right_side = right_bound(i+ 1, n-2, i , nums)  ;
            
            if( right_side >= left_side )
            {
                ans = ans + (right_side- left_side + 1)%mod   ;
               ans = ans%mod;
            }
        }
        
        return ans%mod; 
        
        
    }
};