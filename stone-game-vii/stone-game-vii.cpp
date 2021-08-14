class Solution {
public:

    vector<vector<int>>t ;
    vector<int>presum ;
    
    int rec( int start , int end,  vector<int>&nums )
    {
        if( start > end) return 0 ;
        
        if( t[start][end] != -1) return t[start][end] ;
        
        
        int ans = INT_MIN ;
        
        int left = ( presum[end+ 1] - presum[start] - nums[start] ) - rec( start+ 1, end ,nums) ; // - rec( ) is for the Bob turn 
        int right = (presum[end+ 1] - presum[start] - nums[end] ) - rec( start , end- 1, nums) ;
        
       // cout<<left<<" "<<right<<endl;
        
        ans = max( left , right) ;
        
        return t[start][end] = ans ;
    }
    
    int stoneGameVII(vector<int>& nums) 
    {
        
       // int total = accumulate( nums.begin() , nums.end() , 0) ;  // ALice+ bob
        
        presum.resize( nums.size()+ 1, 0) ;
        presum[0] = 0;
       for( int i= 0 ;i<nums.size() ; i++)
       {
           presum[i+ 1]  = presum[i] + nums[i] ;
       }
        
        t.resize( nums.size()+ 1, vector<int>( nums.size()+ 1, -1) ) ;
        
        int diff = rec(0, nums.size()-1, nums ) ;  //Alice- bob 
        
        return diff;
                  

        
    }
};