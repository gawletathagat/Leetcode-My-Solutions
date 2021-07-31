class Solution {
public:
    
    int rec( vector<int>&piles,vector<vector<int>>&t , int start , int end)
    {
        if(start== end ) return piles[start] ;
        
        if( end- start == 1) return max( piles[start] , piles[end] ) ;
        
        if( t[start][end] != -1) return t[start][end] ;
        
        int first = piles[start] + min(rec(piles,t, start + 1, end - 1), rec(piles,t, start + 2, end));
        int second = piles[end] + min(rec(piles,t, start + 1, end - 1), rec(piles,t, start, end - 2));
        return t[start][end] = max(first, second);
    }
    
    bool stoneGame(vector<int>& piles) 
    {
        int total = accumulate( piles.begin() , piles.end(), 0 ) ;
        int n = piles.size() ;
        vector<vector<int>>t(n+ 1, vector<int>(n+ 1, -1) ) ;
        
        int p1 = rec(piles, t, 0, n-1 ) ;
        cout<<p1;
        
        return (total - p1) < p1 ;   
    }
};