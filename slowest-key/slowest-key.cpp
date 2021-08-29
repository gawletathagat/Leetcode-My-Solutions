class Solution {
public:
    char slowestKey(vector<int>& rt, string kp) 
    {
        
        int index = 0;
        int diff = rt[0] ;
        int max_diff = diff ;
        char ans = kp[0] ;
        for( int i= 1 ; i<rt.size() ; i++)
        {
            diff = abs( rt[i]- rt[i-1]) ;
            
            if( max_diff <= diff )
            {
                if( max_diff == diff)
                {
                   ans = max(ans, kp[i] );
                }
                else
                {
                    max_diff = diff;
                   ans = kp[i] ;
                }
            }
        }
       return ans;
        
    }
};