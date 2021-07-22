class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) 
    {
        sort(e.begin() , e.end() ) ;
        
        // Now LIS 
        int n = e.size() ;
        vector<int>t(n, 1) ;
        
        for( int i= 0; i<n ; i++)
        {
            for( int j= 0 ; j<i; j++)
            {
                if( e[i][0] > e[j][0] && e[i][1] > e[j][1] )
                {
                   t[i] = max( t[i] , t[j]+ 1) ; 
                }
            }
        }
        
        return *max_element( t.begin() , t.end() ) ;
        
        
    }
};