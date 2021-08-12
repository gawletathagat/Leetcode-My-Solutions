class Solution {
public:
    int minJumps(vector<int>& arr) 
    {
        unordered_map<int, vector<int>>mp;
        int n = arr.size() ;
        if( n == 1) return 0;
        
        for( int i= 0 ; i<arr.size() ; i++) mp[arr[i]].push_back( i) ;
        
        queue<int>q ;  // indexes
        q.push(0) ;
        
        int ans = 0 ;
        
        while( !q.empty() ) 
        {
            ans++;
            int q_size = q.size() ;
            
            for( int i= 0 ; i<q_size ; i++)
            {
                int top_index = q.front() ;
                q.pop();
                
                if( top_index-1 >= 0 && mp.find(arr[top_index-1]) != mp.end() )
                {
                    q.push(top_index-1) ;
                }
                
                if( top_index+ 1 <n &&mp.find(arr[top_index+1]) != mp.end() )
                {
                    if( top_index+ 1 == n-1) return ans ;
                    q.push(top_index+ 1) ;
                }
                
                if( mp.find(arr[top_index]) != mp.end() )
                {
                    for(auto x : mp[arr[top_index]] )
                    {
                        if( x!= top_index)
                        {
                            if( x== n-1) return ans ;
                            q.push(x) ;
                        }
                    }
                }
                
                mp.erase(arr[top_index] ) ;
            }
        }
        
        
        return ans ;
    }
};