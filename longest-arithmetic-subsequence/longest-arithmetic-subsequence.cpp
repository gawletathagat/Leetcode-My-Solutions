class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) 
    {
//         if( nums.size() <=1) return nums.size() ;
        
//         unordered_map<int,int> diff_mp ;
//         for( int i= 0 ; i<nums.size() ; i++)
//         {
//             for( int j= 0 ; j<nums.size() ; j++)
//             {
//                 if( i!= j)
//                 diff_mp[abs(nums[i]- nums[j]) ]++ ;
//             }
//         }
        
//         int diff = abs(nums[0] - nums[1] );
//         int occ = 0;
//         for( auto x: diff_mp)
//         {
//             if(occ < x.second ) 
//             {
//                 diff = x.first ;
//                 occ = x.second ;
//             }
//         }
        
//         for( auto x: diff_mp) 
//         {
//             cout<<x.first<<" "<<x.second<<endl ;
//         }
//         cout<<endl;
//         cout<<diff;
        
        // LIS 
        int ans=2;
        int n=nums.size();
          
        //minimum diff is -500 so add 500 to store it in array
        vector<vector<int>> dp(n,vector<int>(1001,1));
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                //if i joins j 
                int diff=nums[i]-nums[j] + 500;  // to keep the array index +ve
                
                dp[i][diff]=max(dp[i][diff],dp[j][diff]+1);
                
                 ans=max(ans,dp[i][diff]);
            }
        }
        
        
        return ans;
    }
};