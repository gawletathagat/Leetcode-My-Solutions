class Solution {
public:
    
    vector<int>size; 
    
    int findP( int u, vector<int>&p )
    {
        if( u == p[u] ) return p[u] ;
        return p[u] = findP(p[u] , p) ;
    }
    
    void Union( int u, int v, vector<int>&p )
    {
        u = findP(u, p ) ;
        v = findP(v , p) ;
        
        if( u == v) return;
        
        if( size[u] > size[v])
        {
            size[u] = size[u] + size[v] ;
            p[u] = v ;
        }
        else 
        {
            size[v] = size[v] + size[u] ;
            p[v] = u ;
        }
       
    }
    
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) 
    {
//         // Dijoint set                        (1, 1*1) (1, 1*2) (1, 1*3) (1,1*4) (1, 1*5) (1*6)  
//                                               (2 , 2*1 ) , (2 , 2*2) ( 2, 2*3)
//                                             _________________(threshhold z = 2) we need more that threshold
//        x % z == 0,                            (3, 3*1)  , (3, 3*2)  
//        y % z == 0, and                        (4, 4*1)               
//        z > threshold.                         (5, 5*1)  
//            this 3 conditions means ,          (6, 6*1) 
                                                  
//                                       // after union   { 1 , 2 , 3---6 , 4, 5 }   
        
        size.resize(n+1 , 1) ;
        vector<int>p(n+1 ) ;
        for( int i= 0 ; i<n+1 ; i ++) p[i] = i ;
        
        for( int z = threshold+ 1; z<=n ; z++) 
        {
            int curr = 1 ; 
            while( curr* z <=n )
            {
                Union( z , curr*z , p) ;
                curr++;
            }
        }
        
        // Union is Completed , we need we see the Queries
        vector<bool>ans_queries ;
        for( int i= 0 ; i<queries.size() ; i++)
        {
            int u = findP( queries[i][0] , p ) ;
            int v = findP( queries[i][1] , p) ;
            
            if( u==v)
            ans_queries.push_back(true) ;
            else 
            ans_queries.push_back(false) ;
        }
        
        return ans_queries ;
    }
};