class Solution {
public:
    
   int parent[201] ;
    void makeParent(int n) 
    {
        for( int i= 1; i<=n; i++)
            parent[i] = i ;
    }
    
    int findParnet( int u)
    {
        // return u == findParnet( u) ? u : u= findParnet(parent[u]) ;
        if( u == parent[u] ) return u ;
        return parent[u] = findParnet( parent[u] ) ;
    }
    
    
    void Union( int u, int v )
    {
        // u and v are the nodes 
        // step-3 => find there parents
        u = findParnet(u) ;
        v = findParnet( v) ;
        
        //step-4 => once parent is found then we just have to attach the u with v 
       if( u != v) parent[v] = u ;   
    }
    
    int findCircleNum(vector<vector<int>>& isConnected)
    {
       // disjoint set 
        
        //do not use the adj list ( No need)
        int n = isConnected.size() ;
                   
      //      | 1   2   3  4
      // -----|------------------          
      //   1->| 1   1   0  0
      //   2->| 1   1   0  0
      //   3->| 0   0   1  0
      //   4->| 0   0   0  1  // self loop
               
        // step-1 => make easch node his own parent 
        makeParent( n) ;  // n is total number of nodes starting fro 1- n
        
        // step-2 => find the nodes parent but only of those whose matrix value is 1 == there is a link
        for( int i= 0 ; i<n ; i++)
        {
            for( int j= i+ 1; j<n ; j++)
            {
                if( isConnected[i][j] ) Union( i , j ) ;
            }
        }
        
        // step-5 => every thing is done and the structure looks like 
        // 1------2
            
       //      3      4

        // step-6 => this step varies with the Q in this Q we have to find different groups so
        
        int groups = 0 ;
        for( int i= 0 ; i<n ; i++)
        {
            if(i == parent[i] ) groups++ ;    // does't find a group { self loop like 3, 4 , 1} 
        }
        
        return groups;
        
        
    }
};