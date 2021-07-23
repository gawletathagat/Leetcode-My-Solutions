class Solution {
public:
     int findNumberOfLIS(vector<int>& v) {
        // finding length of LIS
        
        vector<int> dp(v.size() , 1);
        
       // dp[0] = 1;
        
        for(int i=1; i<dp.size(); i++)
        {
            //int currMax = 0;
            for(int j=0; j<i; j++)
            {
                if(v[j] < v[i])
                {
                    dp[i] = max(dp[i], dp[j]+ 1);
                }
            }
            
           // dp[i] = currMax + 1;
           // lis = max(lis, dp[i]);
        }
         
         int lis = *max_element( dp.begin() , dp.end() ) ;
        
        // counting number of LIS
        
        // create a count vector to count number of subseqeunces
        vector<int> count(dp.size());
        
        for(int i=0; i<count.size(); i++)
        {
            if(dp[i] == 1) count[i] = 1;
            else
            {
                for(int j=0; j<i; j++)
                {
                    if(dp[j] + 1 == dp[i] and v[j] < v[i])
                    {
                        count[i] = count[i] +  count[j];
                    }
                }
            }
        }
         
         for( int i= 0 ; i<dp.size() ; i++) cout<<count[i]<<" ";
        
        // add number of subsequences that has length equal to LIS length
        int ores = 0;
        for(int i=0; i<dp.size(); i++)
        {
            if(dp[i] == lis)
            {
                ores = ores + count[i];
            }
        }
        
        return ores;
    }
};