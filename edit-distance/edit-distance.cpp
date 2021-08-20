class Solution {
public:
    int minDistance(string word1, string word2)
    {
        // i-1, j insert
        // i, j-1  del
       // i-1, j-1  replace 
        
        //LCS 
        int n1 = word1.size() ;
        int n2 = word2.size() ;
        
        // if( n1== 0) return n2;
        // if( n2==0 ) return n1 ;
        
        vector<vector<int>>t(n1+ 1 , vector<int>(n2+ 1) ) ;
        
        for( int i= 0; i<n1+ 1; i++) t[i][0] = i;
        for( int j= 0; j<n2+ 1; j++) t[0][j] = j;
        
        for( int i= 1; i<n1+ 1; i++)
        {
            for( int j= 1; j<n2+ 1; j++)
            {
                if( word1[i-1] == word2[j-1] )
                {
                    t[i][j] = t[i-1][j-1] ;
                }
                else 
                    t[i][j] = min( {t[i-1][j] , t[i][j-1] , t[i-1][j-1]} ) + 1;
            }
        }
        
        return t[n1][n2] ;
        
        
        
    }
};