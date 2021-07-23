class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        // knapsack
        //we put the max in our bag then the (remaing  = total - max) will be our ans 
        
//         S1 + S2 = Total_Sum_of_Array ( say S ) ...... (1)
// Also our answer is S1 - S2 = diff ................... (2)

// S1 - S2 = diff ( from (2) )
// S1 - S2 + 2xS2 - 2xS2 = diff ( adding and subtracting 2xS2)
// S1 + S2 - 2xS2 = diff
// S - 2xS2 = diff ( from (1) )
// Now, our task is to minimize this diff, which is equivalent to maximizing S2 ?
// What can the min value of diff be? 0 right? So what can the max value of S2 be ? S/2 !
        
        int total = accumulate( stones.begin() , stones.end() , 0) ;
        int n = stones.size() ;
        vector<vector<int>>t(n+ 1, vector<int>( total/2+ 1 , 0) ) ; // to store the max we can take
       
         for( int i= 1; i<n+ 1; i++ )
         {
             for(int j= 1; j<total/2+ 1 ; j++  )
             {
                 if( j >= stones[i-1] )
                 {
                     t[i][j] = max( t[i-1][j] , t[i-1][j- stones[i-1]] + stones[i-1] ) ;
                 }
                 else 
                     t[i][j] = t[i-1][j] ;
             }
         }
        
        int maxWt = 0;
        for( int i=1; i<=n; i++ )
            if( t[i][total/2] > maxWt )
                maxWt = t[i][total/2];
        
        return total - 2*maxWt;
    }
};