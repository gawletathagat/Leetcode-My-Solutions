class Solution {
public:
    
    vector<vector<int>>ans ;
    
    void rec( vector<int>&nums, int start, vector<int>&v )
    {
       // if( start >= nums.size()-1 ) return ;
        
         ans.push_back(v);
            
        for( int i= start ; i<nums.size() ; i++)
        {
            v.push_back(nums[i]) ;
            
            rec( nums, i+1, v) ;
            
            v.pop_back() ;
        }
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int>v ;
         rec( nums, 0, v ) ;
        return ans ;
    }
};