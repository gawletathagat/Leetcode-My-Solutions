struct meet{
    int start, end, profit ;
};

class Solution {
public:
    
    static bool cmp(meet a , meet b )
    {
        return a.end < b.end ;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        vector<meet>m( startTime.size()) ;
        for( int i= 0 ; i<startTime.size() ; i++)
        {
            m[i].start = startTime[i] ;
            m[i].end = endTime[i] ;
            m[i].profit = profit[i] ;
        }
        
        sort( m.begin() , m.end() , cmp );
        
        vector<int>curr_profit( startTime.size(), 0) ;
        
        curr_profit[0] = m[0].profit ;
        int ans =INT_MIN ;
        
        for( int i= 1 ; i<startTime.size() ; i++)
        {
            int temp_profit = 0;
            
            for( int j= i-1; j>=0; j--)
            {
                if( m[i].start >= m[j].end ) 
                {
                    // curr_profit[i] = max( curr_profit[i] , m[i].profit ) ;
                    temp_profit = curr_profit[j] ;
                    break;
                   // curr_profit[i] = max( curr_profit[i-1] , curr_profit[j] + m[i].profit )
                }
            }
            
            curr_profit[i] = max( curr_profit[i-1] , temp_profit + m[i].profit ) ;
        }
        
        return curr_profit[startTime.size() -1] ;
        
    }
};