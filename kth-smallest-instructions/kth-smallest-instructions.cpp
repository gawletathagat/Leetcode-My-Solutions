class Solution {
public:
    
    int combination(int n , int r)   // nCr
    {
        int ans= 1;    // (x+y-1)! / (y)!  
        for( int i= 1; i<=r; i++)
        {
            ans = ans*( n-i+ 1) / i ;    
        }
        return ans ;
    }
    
    string kthSmallestPath(vector<int>& nums, int k)
    {
        // generate all the combination // TLE 
        // string s = "" ;
        // for( int i= 0 ; i<nums[1] ; i++) s= s + "H" ;
        // for( int j= 0 ; j<nums[0] ; j++) s= s + "V" ;
        
        string ans ;
        int y = nums[0] ;
        int x = nums[1] ;
        
        int n = x+ y ;
        
        for( int i= 0 ; i<n ; i++)
        {
            if( x) // H    _ _ _ _   nCr compination possible so we fix first element H _ _ _  n-1Cr
            {
                int c = combination( x+ y -1, y ) ;  // n-1Cr
                if( c>=k )
                {
                    ans = ans + "H" ;
                    x-- ;
                }
                else 
                {
                    ans = ans + "V" ;
                    y--;
                    k = k- c; 
                }
            }
            else 
            {
                ans = ans + "V" ;
                y--;
            }
        }
        
        return ans ;
    }
};