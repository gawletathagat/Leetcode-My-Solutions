class Solution {
public:
    int maxSatisfaction(vector<int>& sat)
    {
       // this is a part of knapsack problem lena he ki nahi lena he 
        
        sort( sat.begin() , sat.end() ) ;
        
        int max_sum = 0;
        
        for( int i= 0 ; i<sat.size() ; i++)
        {
            int sum = 0 ;
            int l = 1;
            
            for( int j = i ; j<sat.size() ; j++)
            {
                sum = sum + sat[j]*(l++);
            }
            
            
            cout<<sum<<endl ;
            max_sum = max( max_sum , sum) ;
        }
        
        return max_sum ;
    }
};