class Solution {
public:
    int minimumDeleteSum(string s1, string s2) 
    {
        // find the LCS string 
        int n1 = s1.size() ;
        int n2 = s2.size() ;
        
        vector<vector<int>>t( n1+ 1, vector<int>( n2+ 1, 0) ) ;
        
        for( int i= 1; i<n1+ 1; i++) t[i][0] = t[i-1][0] + s1[i-1] ; 
        for( int j= 1; j<n2+ 1; j++) t[0][j] = t[0][j-1] + s2[j-1] ;
        
        for( int i= 1; i<n1+ 1; i++)
        {
            for( int j = 1; j<n2+ 1; j++)
            {
                if( s1[i-1] == s2[j-1] ) t[i][j] = t[i-1][j-1] ;
                
                else 
                    t[i][j] = min( t[i-1][j] + s1[i-1] , t[i][j-1] + s2[j-1] )  ;
            }
        }
        
        return t[n1][n2] ;
        
//         int LCS = t[n1][n2] ;
//         //cout<<LCS;
        
//         int i = n1;
//         int j = n2 ;
//         string ans = "" ;
        
//         while( i>0 && j>0 )
//         {
//             if( s1[i-1] == s2[j-1] ) 
//             {
//                 ans = ans + s1[i-1] ;
//                 i--, j--;
//             }
//             else 
//             {
//                 if(t[i-1][j] > t[i][j-1] )
//                 {
//                     i--;
//                 }
//                 else 
//                 {
//                     j--;
//                 }
//             }
//         }
        
//         reverse( ans.begin() , ans.end() ) ;
//        // cout<<ans;
        
//         // now ans is our LCS string 
//         int sum_lcs= 0;
//         for( int i = 0 ; i<ans.size(); i++)
//         {
//             sum_lcs = sum_lcs + ans[i] ;
//         }
        
//         int sum_s1= 0;
//         for( int i= 0 ; i<s1.size() ; i++)
//         {
//             sum_s1 = sum_s1+ s1[i] ;
//         }
        
//         int sum_s2 = 0;
//         for( int j= 0; j<s2.size(); j++)
//         {
//             sum_s2 = sum_s2 + s2[j] ;
//         }
        
//         cout<<sum_lcs<<" "<<sum_s1<<" "<<sum_s2 ;
        
//         return sum_s1 + sum_s2 - 2*sum_lcs ;
//         return 0;
        
        
        
    }
};