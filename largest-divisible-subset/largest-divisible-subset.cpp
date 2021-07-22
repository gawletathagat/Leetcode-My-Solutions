class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        // Think LIS
         if(nums.size()==0 || nums.size()==1)
        return nums;
        
        sort( nums.begin() , nums.end() ) ;
        
       vector<int>t( nums.size(), 1) ;
        
        for( int i = 1 ; i<nums.size() ; i++)
        {
            for( int j= 0; j<i ; j++)
            {
                if( nums[i] % nums[j] == 0) 
                {
                   t[i] = max( t[i] , t[j]+ 1) ; 
                }
            }
        }
        
        int maxi = *max_element( t.begin() , t.end() ) ;
        
        int prev= -1;
        int n = t.size()-1; 
        
        vector<int>ans ;
        
        while( n >= 0)
        {
            if( t[n] == maxi && (prev % nums[n] == 0 || prev== -1) )
            {
                ans.push_back(nums[n] ) ;
                maxi-- ;
                prev = nums[n] ;
            }
               
            n-- ;
        }
        
        return ans;
        
        
        
    }
};