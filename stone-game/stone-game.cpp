class Solution {
public:
    vector<vector<int>>t ;
    
    int rec( vector<int>&piles, int start , int end )
    {
        if( start >= end ) return piles[start];
        
        if( end - start  == 1) return max( piles[start] , piles[end ])  ; 
        
        /// space for memoization 
        if( t[start][end] != -1) return t[start][end] ;
        
        int front =  piles[start] + min(rec( piles, start+ 1, end-1) , rec( piles, start+ 2, end));
        
        int back =  piles[end] + min(rec( piles, start+ 1, end-1) , rec( piles, start , end-2) );
        
       
        return t[start][end]  = max( front , back) ;
        
    }
    
    bool stoneGame(vector<int>& piles)
    {
        // like knapsack we have a choice to pick from last and first , we we try every way
        // suppose we are alice so we make our sum as much as possible 
        
       
        int n = piles.size() ;
        
        t.resize( n+ 1, vector<int>( n+ 1, -1) ) ;
        
        int max_alice_sum =  rec( piles, 0, n-1) ;
        
        int bob = accumulate( piles.begin() , piles.end() , 0 ) - max_alice_sum ;
        
        
        cout<<max_alice_sum <<" "<<bob<<endl;
        
        return (max_alice_sum > bob) ? true : false ;
    }
};