class Solution {
public:
    
    
    bool check( string& big , string& small)
    {
        int count = 0;
        
        if( big.size() != small.size()+ 1) return false;
        
        int l1 = 0 , l2 = 0 ;
        
        while( l1< big.size() && l2 < small.size() ) 
        {
            if( big[l1] == small[l2] ) {l1++, l2++;}
            else 
            {
                l1++;
                count++;
            }
        }
        
        return count <=1  ;
    }
    
    int longestStrChain(vector<string>& words) 
    {
        // LIS 
       int n = words.size();
        if(!n)
            return 0;
        int max_idx = 0;
         vector<int> dp(n,1);
        sort(words.begin(),words.end(),[](string &s1,string &s2)
             {
                return s1.size() < s2.size(); 
             });
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(check(words[i],words[j])){
                    dp[i] = max(dp[i] , dp[j] + 1);
                }
            }
            max_idx = max(max_idx , dp[i]);
        }
        return max_idx;
        
    }
};