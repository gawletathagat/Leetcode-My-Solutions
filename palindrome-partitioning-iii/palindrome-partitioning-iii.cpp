class Solution {
public:
    
    vector<vector<int>>t ;
    
    int count_distint( string& s, int i , int j)
    {
        int count = 0 ;
        while( i<j)
        {
            if( s[i] != s[j]) count++;
            
            i++;
            j-- ;
        }
        
        return count;
    }
    
    int rec( int i, int k , string& s)
    {
        if( i >= s.size() )
        {
            if( k==0 ) return 0 ;

                return 1e5 ;
        }
        
        cout<< i<<" ";
        
        if( k==0 ) return 1e5 ;  // b  bccd -> last part to remeaning reh gaya 
        
        if( t[i][k] != -1) return t[i][k] ;
        
        long long int ans = 1e5 ;
        
        for( int j = i ; j<s.size() ; j++)
        {
            long long int  prev_count =  count_distint(s, i, j) + rec( j+ 1, k-1, s)  ;
            //ans = min( ans ,);
            if( ans > prev_count)
                ans = prev_count ;
        }
        
        return t[i][k] = ans ;        
    }
    
    int palindromePartition(string s, int k) 
    {
        // MCM , we use recursion
        
        //aabbccd  , k = 3 , ans == 1
        int n = s.size() ;
        
        if( k > s.size()-1) return 0;
        
        t.resize(n+ 1, vector<int>( k+ 1, -1) ) ;
        
        long long int result = rec( 0 , k , s) ;
        
        cout<<result;
        
       return result >= 1e5 ? 0 : result ; 
    }
};