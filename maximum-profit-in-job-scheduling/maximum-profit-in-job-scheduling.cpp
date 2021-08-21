
struct meet{
    int start, end, profit ;
};

class Solution {
public:
    static int cmp( meet a, meet b)
    {
        return a.end < b.end ; // starting order of end time
    }
    
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& profit)
    {
        vector<meet>m(s.size()) ;
        for( int i= 0 ; i<s.size() ; i++)
        {
            m[i].start = s[i] ;
            m[i].end = e[i] ;
            m[i].profit = profit[i] ;
        }
        
        sort(m.begin() , m.end() , cmp) ;
       
        
        int t[s.size()];   // track max_profit upto
        
        t[0] = m[0].profit ;
        
        for( int i= 1 ;i<s.size() ; i++)   // 0---->job[j]--->job[i]-----> job[s.size()] 
        {
            int upto_profit = 0;
            for( int j= i-1 ; j>= 0 ; j--)
            {
                if( m[i].start >= m[j].end )
                {
                    upto_profit = t[j] ;
                    break;
                }
            }
            t[i] = max( t[i-1] , upto_profit + m[i].profit )  ;
        }
        
        return t[s.size()-1] ;
        
    }
};