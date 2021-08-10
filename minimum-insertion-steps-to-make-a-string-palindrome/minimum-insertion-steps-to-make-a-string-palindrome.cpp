class Solution {
public:
    
    int rec( string& p, string& s)
    {
        int n = s.size() ;
        vector<vector<int>>t(n+ 1, vector<int>(n+ 1, 0) ) ;
        
       for( int i= 1; i<n+1 ; i++)
       {
           for( int j= 1; j<n+1 ; j++)
           {
               if( s[i-1] == p[j-1] )
               {
                   t[i][j] = 1+ t[i-1][j-1] ;
               }
               else 
               {
                   t[i][j] = max( t[i-1][j] , t[i][j-1] ) ;
               }
           }
       }
        
        return t[n][n] ;
    }
        
    
    int minInsertions(string s) 
    {
        // total - LCS 
        
        //now for LCS
        string p = s ;
        reverse( s.begin() , s.end() ) ;
        
        int LCS = rec( p , s) ;
        cout<<LCS ;
        
        return s.size()- LCS ;
        
    }
};