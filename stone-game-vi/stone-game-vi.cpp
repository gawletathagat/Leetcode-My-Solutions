class Solution {
public:
    int stoneGameVI(vector<int>& A, vector<int>& B)
    {
        // this is nat a DP problem 
        // we just have to make a vector to store the (profit_ALice + loss_Bob) 
        
        // profit of ALice  = profit of ALice + loss of Bob 
        
        //aliceValues = [1,2], bobValues = [3,1]
        //we could choose 2 but then bob left with 3 , so we choose 1 se that bob has to choose 1 
        
        vector<pair<int,int>>v ;  
        for( int i= 0 ;i <A.size() ; i++)
        {
            v.push_back( {A[i]+ B[i] , i} ) ;
        }
        
        sort( v.begin(), v.end() ,greater<pair<int,int>>() ) ;
        
        int alice_profit = 0 , bob_profit = 0 ;
        bool f = false; // turn kisi he 
        
        for( int i= 0 ; i<v.size() ; i++)
        {
            if( f == false)
            alice_profit = alice_profit + A[v[i].second ] ;
            
            if( f == true )
            bob_profit = bob_profit + B[v[i].second] ;
            
            f = 1- f ;  //  change the turns 
        }
        
        cout<< alice_profit <<" "<<bob_profit ;
        
        if(alice_profit > bob_profit ) return 1;
        
        else if( alice_profit < bob_profit) return -1;
        
        return 0;
        
    }
};