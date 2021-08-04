class Solution {
public:
    
    int findParent( vector<int>&parent , int i)
    {
        if( parent[i] == i) return i ;
        return parent[i] = findParent( parent, parent[i] ) ;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        // Disjoint set , union find
        int n = accounts.size() ;
        vector<int>parent(n, 0 ) ;
        unordered_map<string, int> email ;
        
        for( int i = 0 ; i<n ; i++) 
        {
            parent[i] = i ;
            
            for( int j= 1; j<accounts[i].size() ; j++)
            {
                if( email.find(accounts[i][j]) != email.end() ) 
                {
                    int f1 = findParent( parent , i) ;
                    int f2 = findParent( parent , email[accounts[i][j]] ) ;
                    
                    parent[f1] = f2 ;
                }
                else 
                {
                    email[accounts[i][j]] = i;
                }
            }
        }
        
        unordered_map<int , vector<string> > mres ;  // this is ower ans , unsorted
        for( auto it : email)
        {
            int f = findParent(parent, it.second );
            mres[f].push_back(it.first );
        }
        
        
        vector<vector<string>>res ;
        for( auto it: mres)
        {
            sort( it.second.begin(), it.second.end() ) ;
            
            vector<string>temp = {accounts[it.first][0] } ;
            
            for( auto i: it.second ) temp.push_back(i) ;
            
            res.push_back( temp ) ;
        }
        
        return res;
        
        
        
        
    }
};