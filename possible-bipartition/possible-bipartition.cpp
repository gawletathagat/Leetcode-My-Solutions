class Solution {
public:
    bool dfs(vector<vector<int>>&adj, vector<int>&color , int node )
    {
        for( auto x: adj[node])
        {
            if( color[x] == 0)
            {
                color[x] = 1- color[node] ;
                if( dfs( adj, color, x) == false ) return false;  
            }
            
            else if( color[x] == color[node] )return false;
        }
        
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& d)
    {
        vector<vector<int>> adj(n+1);
        
        for(int i=0;i<d.size();i++)
        {
            adj[d[i][0]].push_back(d[i][1]);
            adj[d[i][1]].push_back(d[i][0]);
        }
        
        vector<int>color(n+1, 0) ;
        
        for( int i= 1; i<=n;  i++)
        {
             if( color[i]== 0)
            {
                if( dfs( adj , color, i) == false) return false;
            }
        }
        return true;
    }
};