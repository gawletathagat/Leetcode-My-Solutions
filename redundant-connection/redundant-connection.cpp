class Solution {
public:
    
    int parent[1001] ;
    void makeParent( int n)
    {
        for( int i= 1; i<=n; i++) parent[i] = i ;
    }
    
    
    int findParent( int u)
    {
        if( u == parent[u] ) return u ;
        return findParent(parent[u] ) ;
    }
    
    bool Union( int u , int v)
    {
        u = findParent(u) ;
        v = findParent(v) ;
        
        if( u!= v) // nodes are diff
        {
            parent[u] = v ;
        }
        else 
        {
            // that means this is a redundent link so , this is our answer , we store it ;
            
            return true;
        }
        
        return false;
        
        
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        // this is DisJoint set
        
        int n = edges.size() ;
        
        // step-1 => make each node its own parent 
        makeParent(n) ;
        
        // step-2=> add links between nodes
        for( int i= 0 ; i<n ; i++)
        {
            if(  Union( edges[i][0] , edges[i][1] )  ) return { edges[i][0] , edges[i][1]} ;
        }
        
        return {-1, -1} ;

    }
};