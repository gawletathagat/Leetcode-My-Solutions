class Solution {
public:
    
    vector<int>size;
    
    int findP( int u , vector<int>&p )
    {
        if( u== p[u] ) return p[u] ;
        return p[u] = findP(p[u], p ) ;
    }
    
    void Union( int u , int v , vector<int>& p )
    {
        u = findP(u, p) ;
        v = findP(v, p) ;
        
        if( size[u] > size[v] )
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
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
    {
         //this is a graph Q
        // pairs aree the connected components
        int n = s.size() ;
        size.resize(n+1, 1) ;
        
        vector<int>p(n+1) ;
        for( int i= 0 ; i<p.size() ; i++) p[i] = i ;
        
        for( int i= 0 ; i<pairs.size() ; i++)
        {
            int first = pairs[i][0] ;
            int second = pairs[i][1];
            
            Union(first , second , p);
        }
        
        vector<vector<int>>store(n) ;
       // now get the all characters that have same root and sort them
        
        for( int i = 0 ; i<n ; i++)
        {
            int q = findP(i , p) ;
            
            store[q].push_back(i) ;
        }
        
        for( auto ind : store )
        {
            string ss = "" ;
            for( auto i : ind)
            {
                ss.push_back(s[i]) ;
            }
            
            sort(ss.begin() , ss.end() ) ;
            
            int j= 0 ;
            for( auto i: ind)
            {
                s[i] = ss[j++] ;
            }
            
        }
        return s;
    }
};