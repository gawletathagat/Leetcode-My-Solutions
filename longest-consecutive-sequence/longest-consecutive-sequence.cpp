class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if( nums.size() <=1  ) return nums.size() ;
       
        unordered_map<int, int>mp ;
        
        for( int i= 0 ; i<nums.size() ; i++) mp[nums[i]] = i ;
        
        int count = 0 , maxi = 0;
    
        set<int>st( nums.begin() , nums.end() );
        
       vector<int>v(st.begin() , st.end() );
        
        for( int i = 0 ; i<v.size() ; i++)
        {
            if( mp.find(v[i] + 1) != mp.end() )
            {
                count++;
            }
            else 
            {
                maxi = max( maxi , count) ;
                count = 0;
            }
        }
        
        maxi = max( maxi , count) ;
        return maxi + 1 ;
        
    }
};