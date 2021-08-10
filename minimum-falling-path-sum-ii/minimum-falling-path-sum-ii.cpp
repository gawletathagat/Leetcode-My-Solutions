class Solution {
public:
    
    int n, m ;
 //  int t[201][201];
    vector<vector<int>>t;
    
    int rec( int i, int j , vector<vector<int>>&arr)
    {
        if( i== n) return 0 ;
        
        if( i<0 || j<0 || j>=m) return INT_MAX ;
        
        if( t[i][j] != -1) return t[i][j] ;
        
        int min_in_curr_row = INT_MAX ;
        
        for( int y= 0 ; y<m ; y++)
        {
            if( y== j) continue ;
            
            min_in_curr_row = min( min_in_curr_row , arr[i][j] + rec( i+ 1, y, arr ) ) ;
        }
        
        return t[i][j] = min_in_curr_row ;
    }
    
    int minFallingPathSum(vector<vector<int>>& arr) 
    {
        // we know that once we fixed the road we have to find the min element in col 
         n = arr.size() ;
         m = arr[0].size() ;
        
        t.resize( n+ 1, vector<int>( m+ 1, -1)) ;
        // memset(t,-1,sizeof(t));
        
        int sum = INT_MAX ;
        // we are checking for every col 
        // 1,2,3,4         // find all the ans starting form 1 , then starting for 2
        // 5,6,7,8
        // 9,10, 11,12
        
        for( int j= 0 ; j<m ; j++)
        {
            sum = min( sum , rec(0, j, arr ) ) ; 
        }
        return sum ;  
    }
};