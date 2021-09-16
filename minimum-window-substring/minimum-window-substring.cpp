class Solution {
public:
    string minWindow(string s, string t)
    {
        if( s.size() == 0 || t.size() > s.size() ) return "" ;
        
        int i= 0 , start = 0 ;
        int req = t.size() ;
        int min_size = INT_MAX; 
        int left = 0;
        
        unordered_map<char, int> mp;
        for( int i= 0 ; i<t.size() ; i++) mp[t[i]]++;
        
        while( i<=s.size()  && start<s.size() )
        {
            if( req > 0)
            {
                if( i== s.size() ) break;
                mp[s[i]]--;
                if( mp[s[i]] >=0 ) req--;
                i++;
            }
            else 
            {
                if( i-start < min_size )
                {
                    min_size = i-start ;
                    left= start;
                }
                mp[s[start]]++;
                if( mp[s[start]] > 0 ) req++;
                start = start+ 1;
            }
        }
        
       if( min_size != INT_MAX ) return s.substr( left , min_size ) ;
        return "" ;
        
    }
};