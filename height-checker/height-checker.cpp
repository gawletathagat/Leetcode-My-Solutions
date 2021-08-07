class Solution {
public:
    int heightChecker(vector<int>& heights) 
    {
        vector<int>v( heights.begin() , heights.end()) ;
        
        sort( heights.begin() , heights.end() ) ;
        
        int count = 0;
        for( int i= 0 ; i<v.size() ; i++)
        {
            if( v[i] != heights[i] ) count++;
        }
        return count ;
        
    }
};