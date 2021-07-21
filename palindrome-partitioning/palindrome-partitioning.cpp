class Solution {
public:
    
    bool isPalindrom( string p)
    {
        int l = 0 , r = p.size()-1;
        while( l<r)
        {
            if( p[l] != p[r] ) return false;
            l++, r--;
        }
        return true;
    }
    
    void rec( string s ,int start_index , vector<string>&v, vector<vector<string>>&ans)
    {
       if( start_index == s.size() ) 
       {
           ans.push_back(v) ;
           return ;
       }
        
        
        for( int k= start_index ; k<s.size() ; k++)
        {
            string p = s.substr( start_index , k-start_index + 1) ;
           // string q = s.substr( k+ 1 , end_index ) ;
            
            if( isPalindrom( p)  )
            {
                v.push_back(p);
                
                 rec( s, k+ 1 , v, ans) ;
                v.pop_back() ;
            }
        }
    }
    
    
    vector<vector<string>> partition(string s)
    {
        // this is an MCM Question , and we dont know were to break so we break after every position 
        
        int n = s.size() ;
        //vector<vector<bool>>t(n+ 1, vector<bool>(n+ 1,false ) );
        vector<string> v ;
        vector<vector<string>>ans ;
        
         rec( s, 0, v, ans) ;
        return ans ;
    }
};