class Solution {
public:
    int trap(vector<int>& nums) 
    {
        if( nums.size() <=1 )return 0;
        int sum = 0 ;
        
        vector<int>L(nums.size()+ 1, 0) ;
        
        for( int i= 1 ; i<nums.size()-1 ; i++)
            L[i] = *max_element(nums.begin(), nums.begin() + i);
        
//         L[0] = nums[0];
//          for( int i= 1 ; i<nums.size()-1 ; i++)
//          {
//              L[i] = max( L[i-1] , nums[i] ) ;
//          }
        
        
        // for( int i= 0 ; i<L.size() ; i++) cout<<L[i]<<" ";
        // cout<<endl;
        
       
        
        vector<int>R(nums.size()+ 1, 0) ;
        
        for( int i= 1 ; i<nums.size()-1 ; i++)
           R[i] = *max_element(nums.begin()+i, nums.end() ); //Right Max
        
//         R[nums.size()-1] = nums[nums.size()-1] ;
//         for( int i= nums.size()-2 ; i>=1 ; i--)
//         {
//             R[i] = max( R[i+1] , nums[i] ) ;
//         }
        
        
        // for( int i= 0; i<R.size() ; i++) cout<<R[i]<<" ";
        // cout<<endl;
        
        
        
        
        for( int i= 1 ;i<nums.size()-1 ; i++)
        {
            int left = L[i] ;
            // for( int j = 0 ; j<i ; j++)
            // {
            //     left = max( left, nums[j]) ;
            // }
            
            int right = R[i] ;
            // for( int k = i+ 1; k<nums.size() ; k++)
            // {
            //     right = max( right , nums[k] );
            // }
            
           if( min( left, right) - nums[i]  >=0)  sum = sum + min(left, right) - nums[i] ;
            
        }
        
        return sum ;
        
    }
};