class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) 
    {
        vector<long long int >presum( s.size() , 0) ;
        int n = s.size() ;
        presum[n-1]= shifts[n-1] ;
        
        for( int i= 1 ; i<shifts.size() ; i++)
        {
            presum[n-i-1] = presum[n-i] + shifts[s.size()-i-1] ;
        }
        
        for( int i= 0 ; i<presum.size() ; i++) cout<<presum[i]<<" ";
        
        for(int i = 0;i < s.size() ; i++)
       {
         long long index = ((s[i] + presum[i]- 'a') % 26);
            s[i] = 'a' + index;            
       }
     return s;
    }
};