class Solution {
public:
    
    int rec( int n , vector<int>&cuts, int start_index, int end_index, vector<vector<int>>&t) 
    {
        if( end_index - start_index <=1 ) return 0;
        
        if( t[start_index][end_index] != -1) return t[start_index][end_index] ;
        
        int ans = INT_MAX; 
        
        for( int i=start_index+ 1 ; i<end_index ; i++ )
        {
            int temp =  rec( n, cuts, start_index , i, t) +
                        rec( n, cuts, i, end_index, t )   + 
                        cuts[end_index] - cuts[start_index] ;
            
            ans = min( ans, temp) ;
        }
        
        return t[start_index][end_index] = ans ;
        
    }
    
    int minCost(int n, vector<int>& cuts) 
    {
        // cost == {cuts[j] - cuts[i] }  this is the length and also the cost
        
        vector<vector<int>>t(103, vector<int>(103, -1) ) ;
        
        cuts.insert(cuts.begin() , 0) ;
        cuts.push_back(n) ;
        
        sort(cuts.begin() , cuts.end() ) ;
        
        return rec( n , cuts, 0, cuts.size()-1, t) ;
    }
};