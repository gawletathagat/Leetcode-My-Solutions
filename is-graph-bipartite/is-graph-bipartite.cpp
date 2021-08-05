class Solution {
public:
    
    bool dfs( vector<vector<int>>& graph , vector<long>&color , int node)
    {
        for( auto x: graph[node] )
        {
            if( color[x] == 0)
            {
                color[x] = 1-color[node] ;
                
                if( dfs( graph , color, x) == false )return false;
            }
            else if( color[x] == color[node] ) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size() ;
        vector<long>color(n, 0 );
        
        for( int i= 0 ; i<n ; i++)
        {
            if( color[i] == 0)
            {
                if( dfs( graph, color, i) == false) return false;
            }
        }
        return true;
    }
};