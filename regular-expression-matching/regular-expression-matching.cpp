class Solution {
public:
    bool isMatch(string s, string p) 
    {
        // reverse(s.begin(), s.end());
        // reverse(p.begin(), p.end());
        
          int m = s.length(), n = p.length();

         vector<vector<bool>>t(s.size()+ 1 , vector<bool>(p.size()+1, false));
        t[0][0] = 1;
        
        for( int j= 1; j<=p.size() ; j++ ) 
        {
            if( p[j-1] =='*' )
                t[0][j] = t[0][j-2];  //p =="*dfg" is invalid 
        }
       
        for( int i=1 ; i<=s.size() ; i++)
        {
            for( int j= 1; j<=p.size(); j++)
            {
                if(p[j-1]=='.' || p[j-1]==s[i-1] )
                    t[i][j] = t[i-1][j-1];
                
                else if( p[j-1]=='*')
                {
                    t[i][j]= t[i][j-2] ;  // zero occurance go back 2 steps a*
                    
                    if( p[j-2] =='.' || p[j-2] == s[i-1] )
                    t[i][j] = t[i][j] || t[i-1][j] ; 
                }
                else 
                    t[i][j] = false;
            }
        }
        
        for( int i=0 ; i<=s.size() ; i++) 
        {
            for( int j = 0 ; j<=p.size(); j++) cout<<t[i][j]<<" ";
            cout<<endl;
        }
        return t[s.size()][p.size()];
        
    }
};