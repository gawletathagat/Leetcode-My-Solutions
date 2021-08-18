class Solution {
public:
    
    vector<vector<int>>ans ;
    //keep track of visited elements
    bool vis[100000];
	//keep track of detection times
    int d[100000];
	//keep track of lowest detection times
    int l[100000];
    
    void dfs( vector<vector<int>>&graph, int node , int parent , int &timer)
    {
        vis[node] = true;
        
        l[node] = timer+ 1;  // initally both have the same timer
        d[node] = timer+ 1;
        
        timer = timer + 1 ;
        for( auto x: graph[node])
        {
            if( x == parent) continue;
            
            if( !vis[x] )
            {
                dfs( graph, x, node, timer) ;
                
                l[node] = min( l[node] , l[x] ); // back link
                
               //if this condition is satisfied then this edge is a bridge( critical link )
                if(l[x]>d[node])
                {
                    ans.push_back({node ,x }) ;
                } 
            }
             else 
            {
                l[node] = min( l[node] , l[x] ) ;
            }
        }  
    }
    
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
         // Trajan's Algo 
        
        vector<vector<int>> graph(n);
        //make a graph
        for(int i=0;i<connections.size();i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        
        int timer=0;
        
        dfs(graph,0,-1,timer);
        
        return ans;
    }
};