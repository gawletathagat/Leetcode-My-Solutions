class Solution {
public:
    
    int t[14][20000] ;
    
    int rec( int i ,vector<int>& nums1, vector<int>& nums2, int mask )
    {
       if( i == nums1.size()) return 0 ;
        int ans = INT_MAX/2 ;
        
        if(t[i][mask] != -1 ) return t[i][mask] ;
        
        for( int j= 0; j<nums2.size() ; j++ )
        {
//          
            if( (mask &(1<<j)) == 0 ) // checking that mask set bit is 1 or not- If not then this is not visited
            {
                int xor_sum = (nums1[i]^nums2[j]) + rec( i+ 1, nums1, nums2, mask|(1<<j) ) ; // makeing set bit 1 - visited
                ans = min( ans , xor_sum) ;
            }
        }
        
        return t[i][mask] = ans ;
    }
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) 
    {
        // brute force
        memset(t, -1, sizeof(t) ) ;
        
        return rec( 0 , nums1, nums2, 0 ) ;
    }
};