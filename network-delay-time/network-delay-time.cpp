class Solution {
public:
    int networkDelayTime(vector<vector<int>>& time, int n, int k) 
    {
        //dijkstra's algo 
//         we always use the BFS to find shortest path but in this Q we have weighted graph
//         We need some road map to go , we can not use Topo Sort because it only work in DAG
//         so we need to go to the shortest edge , that means we need sorting ( PQ  is best for this )    
         vector<vector<pair<int, int>>> adj(n+ 1) ;
        
        for( int i= 0 ; i<time.size() ; i++)
        {
            adj[time[i][0]].push_back({time[i][1] , time[i][2]} ) ;
            //adj[time[i][1]].push_back({time[i][0] , time[i][2]} ) ;
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int, int>> > pq ;
        
        vector<int>dist( n+ 1, INT_MAX) ;
        
        dist[k] = 0;         // node 1, dist 0
        pq.push( {0, k}) ;      // dist 0 and node 1
        
        while( !pq.empty() )
        {
            int prev_dist = pq.top().first ;
            int prev_node = pq.top().second ;
            pq.pop() ;
            
            for( auto x: adj[prev_node])
            {
                int next_node = x.first ; // 2 1 1 //2(prev_node) -> 1(next_node) 1(next_dist)
                int next_dist = x.second ;
                
                if( dist[next_node] > dist[prev_node] + next_dist )
                {
                    dist[next_node] = dist[prev_node] + next_dist ;
                    
                    pq.push({dist[next_node] , next_node}) ;
                }
            }
        }
        
        int res = *max_element(dist.begin()+ 1, dist.end());
        
        return res == INT_MAX ? -1 : res;
        
        
    }
};