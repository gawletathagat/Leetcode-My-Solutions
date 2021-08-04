class Solution {
public:
    
    void dfs( unordered_map<int, vector<int>>&adj , int curr_start , vector<int>&informTime, int curr_sum, int& max_sum )
    {
        curr_sum  = curr_sum + informTime[curr_start] ;
        
        max_sum = max( max_sum , curr_sum ) ;
        
        for( auto x : adj[curr_start] )
        {
            dfs( adj, x , informTime, curr_sum, max_sum );
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        // first we creat a adj list
        
        unordered_map<int, vector<int>>adj;
        for( int i= 0 ; i<n ; i++)
        {
            if( manager[i] != -1)
                adj[manager[i]].push_back(i) ;
        }
        
        int curr_sum = 0, max_sum = 0;
        
       dfs( adj, headID,informTime, curr_sum , max_sum ) ;  
        
        return max_sum ;
    }
};