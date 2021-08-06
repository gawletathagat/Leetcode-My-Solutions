class Solution {
public:
    
    bool isCycle( int node,vector<int> adj[] , vector<int>&vis )
    {
        if( vis[node] == 1) return true;  // yes cycle he 
        
        if( vis[node] == 0)
        {
            vis[node] = 1;
            
            for( auto x: adj[node] )
            {
                if( isCycle( x, adj, vis) == true) return true;
            }
        }
        
       vis[node] = 2;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre)
    {
        // this is  topo Sort 
        // step-1 -> create a adj list
        //vector<int>adj(n+1, 0) ;
       vector<int> adj[n];
        
        for( auto edges : pre )
            adj[edges[1]].push_back(edges[0]) ;
        
        vector<int>vis( n, 0) ;
        
        for( int i= 0; i<n ; i++)
        {
            if( isCycle( i , adj, vis) ==  true ) return false;
        }
        
        return true;
    }
};