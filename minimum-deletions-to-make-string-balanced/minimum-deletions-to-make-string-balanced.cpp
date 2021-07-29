class Solution {
public:
    int minimumDeletions(string s) 
    {
        int n = s.size() ;
        vector<int>t(n+1, 0) ;
        int b_count = 0;
        for( int i= 0 ; i<s.size() ; i++)
        {
            if( s[i] == 'a')
            {
                t[i+ 1] = min( t[i]+ 1, b_count) ; 
            }
            else if( s[i] == 'b')
            {
                t[i+ 1] = t[i] ;
                b_count++;
            }
        }
        
        return t[n] ;
        
    }
};