class Solution {
public:
   // vector<string>ans ;
     unordered_map<string , int>mp ;
    string ans = "" ;
   vector<string>dp ;
    
    bool check( string temp)
    {
        if(mp.find( temp) == mp.end()) 
        {
            ans = temp ;
            return true;
        }
        return false;
    }
    
    string rec( int n , vector<char>v , int i )
    {
       if( dp[i] != "") return dp[i] ;
        
        if( i== n)
        {
            string temp = "" ;
            for( int j = 0 ; j<v.size() ; j++) temp = temp + v[j] ;
            if( check( temp) ) return dp[i]= ans ;
            return dp[i] = ans;
        }
        
        v[i] = '0' ;
        rec( n , v ,  i+1) ;
        
        v[i] = '1' ;
        rec( n , v ,  i+ 1) ;
        
        return dp[i] = ans; 
    }
    
    string findDifferentBinaryString(vector<string>& nums) 
    {
        int n = nums[0].size() ;
        
        dp.resize(n+1 , "") ;
        
        vector<char>v(n) ;
         for( int i= 0 ;i<nums.size() ; i++) mp[nums[i]] = i ;
        
     //   cout<<dp[n-1] ;
       return rec(  n , v , 0) ;
        
        return ans ;        
    }
};