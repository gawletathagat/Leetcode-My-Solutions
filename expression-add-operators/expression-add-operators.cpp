
class Solution {
public:
    
    vector<string>ans ;
    
    void dfs( string& s, int target ,string path , int index, long long int prev_result, int long long  curr_result )
    {
        if( index== s.size() && curr_result == target ) 
        {
          ans.push_back(path) ;
            return ;
        }
        
        long long int number = 0 ;
        string p = "" ;
        
        for( int i =index ; i<s.size() ; i++)
        {
            p = p + s[i] ;
            number = (number*10) + (s[i]-'0') ;
            
            if( p.size() > 1 && p[0] == '0' ) break;
            
            if( index==0 )
            {
                dfs( s, target, p, i+1, number, number) ;
            }
            else
            {
                dfs( s, target, path + "+" + p , i+1, number, curr_result + number ) ;
                dfs( s, target, path + "-" + p , i+1, -number, curr_result - number ) ;
                dfs( s, target, path + "*" + p , i+1, prev_result*number , (curr_result-prev_result) + number*prev_result ) ;
            }
        }
    }
    
    vector<string> addOperators(string s, int target)
    {
        //string path = "" ;
        dfs(s, target, "" , 0 , 0, 0 ) ;
        return ans; 
    }
};