class Solution {
public:
    
    double rec( int i , int j , int n , int k , vector<vector<vector<double>>>&t)
    {
        if( i<0 || j<0 || i>=n || j>=n) return 0 ;
        
        if( t[i][j][k] != -1) return t[i][j][k] ;
        if( k==0)return 1;
        
          // 8 times
        double ans =  rec( i-2, j-1, n, k-1,  t)
               +rec( i-1, j-2, n, k-1,  t)
               +rec( i-2, j+1, n, k-1,  t)
               +rec( i-1, j+2, n, k-1,  t)
               +rec( i+1, j-2, n, k-1,  t)
               +rec( i+2, j-1, n, k-1,  t)
               +rec( i+1, j+2, n, k-1,  t)
               +rec( i+2, j+1, n, k-1,  t);
        
        ans = ans/8 ;
        t[i][j][k] = ans ;
        return t[i][j][k] ;     
    }
    
    double knightProbability(int n, int k, int row, int col) 
    {
        //to find prob we have to div ans/8.0
        
       vector<vector<vector<double>>>t(n+1, vector<vector<double>>(n+1, vector<double>(k+1, -1)));
        return rec( row , col, n , k, t);
    }
};