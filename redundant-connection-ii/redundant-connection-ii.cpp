class Solution {
public:
    
    int find(int x, vector<int>&parent)
    {
        if( parent[x] == x) return x ;
        return parent[x]= find(parent[x] , parent) ;
    }
    
    void _union(int u , int v,  vector<int>&parent , vector<int>&rank )
    {
        int lx = find(u, parent) ;
        int ly = find(v, parent) ;
        
        if( lx!= ly)
        {
            if( rank[lx] > rank[ly] ) parent[ly] = lx ;
            else if( rank[lx] < rank[ly]) parent[lx] = ly ;
            else 
            {
                parent[ly] = lx ;
                rank[lx]++;
            }
        }
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges)
    {
       int n = edges.size() ;
        vector<int>parent( n+ 1, -1);
        vector<int>rank(n+ 1, 1) ;
        
        for( int i= 1 ; i<=n ; i++) parent[i] = i ;
        
        vector<int>adj[n+ 1] ;
        vector<int>ind(n+ 1, -1) ;
        
        int bl1= -1, bl2 = -1;  // bl == BlackList nodes
        
        
        // case-1 cycle 
        for( int i= 0 ; i<n ; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]) ;
            
            if( ind[edges[i][1]] != -1)
            {
                bl1= i ;
                bl2= ind[edges[i][1]] ;
                continue ;
            }
            
            ind[edges[i][1]] = i ;
        }
        
        // case- 2 dsu ( redundent concetion)
        if( bl1 == -1)
        {
            vector<int>ans ;
            for( auto x: edges)
            {
                int u = x[0] ;
                int v = x[1] ;
                
                if( find(u, parent) != find(v, parent) )
                {
                    _union( u, v, parent, rank) ;
                }
                else 
                    ans =x ;
            }
            return ans ;
        }
        else 
        {
            bool isCycle = false; 
            cout<<bl1<<" "<<bl2<<endl; 
            
            for( int i = 0 ; i<edges.size() ; i++)
            {
                int u = edges[i][0] ;
                int v = edges[i][1] ;
                
                if( i== bl1) continue ;
                
                if( find(u, parent) != find(v, parent) )
                    _union(u, v, parent,rank) ;
                else 
                {
                    isCycle = true;
                    break;
                }
            }
            
            if( isCycle == true) return edges[bl2] ;
            
            else if( isCycle == false) return edges[bl1] ;
        }
        return {};
    }
};