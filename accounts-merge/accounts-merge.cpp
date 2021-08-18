class Solution {
public:
     
    int findP( int u , vector<int>&p )
    {
        if( u == p[u]) return p[u] ;
        return p[u] = findP( p[u] , p) ;
    }
    
    void Union( int u, int v, vector<int>&p )
    {
        u = findP(u, p);
        v = findP(v, p) ;
        
      //  if( u!= v)
            p[u] = v ;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        int n = accounts.size() ;
        vector<int>p( n) ;
        
        for( int i= 0 ; i<n ; i++)
        {
            p[i] =i;   // make parent
        }
        
        
        unordered_map<string, int>mp ;
        for(int i= 0; i<accounts.size() ; i++ )
        {
            for( int j= 1; j<accounts[i].size() ; j++)
            {
                if( mp.find(accounts[i][j]) != mp.end() )  // is this email as found earlier 
                {
                    Union( i , mp[accounts[i][j]] , p ) ;   // this email "i" , is found on "mp[accounts[i][j]]" index before so we merge them
                }
                else 
                    mp[accounts[i][j]] = i;    // email, name_index
            }
        }
        
        // we got the answer , but in unsorted manner
        
       unordered_map<int, vector<string>> mres ;
        for( auto x: mp)           // x.first = emails, x.second = names
        {
            int u = x.second ;         // all name index
            cout<<u<<" ";             
            
            int v = findP(u , p) ;   // all unique name index 
            
            mres[v].push_back(x.first) ;     // names, emails
        }
        
        vector<vector<string>>ans ;
        for( auto x :mres)
        {
            sort(x.second.begin() , x.second.end() ) ;   
        
            vector<string>temp ;
            temp.push_back(accounts[x.first][0]) ;  // add person name
            
            for( auto it: x.second)  // x.first == person name , x.second = emails
            {
               // cout<<it<<" ";
                temp.push_back(it) ;   // then all its emails
            }
            
            ans.push_back(temp) ;   // add this all info about a person in ans
        }
        
        return ans ;
        
    }
};