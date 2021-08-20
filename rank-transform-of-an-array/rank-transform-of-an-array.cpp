class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
       // we can use the lower bound
        vector<int>v( arr.begin() , arr.end() ) ;
        sort(v.begin() , v.end() ) ;
        
        unordered_map<int,int>mp ;
        for(int i= 0 ; i<v.size() ; i++) 
        {
            if( mp.find(v[i]) == mp.end() ) // first time
            {
                mp[v[i]] = mp.size() + 1;
            }
        }
        
       for( int i= 0 ; i<arr.size() ; i++)
       {
           arr[i] = mp[arr[i]] ;
       }
        
        return arr;
        
        
    }
};