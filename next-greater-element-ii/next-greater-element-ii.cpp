class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& h) 
    {
        //aditya verma 
        
         int n= h.size();
        
         h.resize(2*n);
        
        for(int i=n; i<2*n; i++) //concatenate the same array
        {
            h[i] = h[i-n];
        }
        
        stack<int>sk ;
        //sk.push(-1) ;
        
        vector<int>v ;
        
       for( int i= h.size()-1 ; i>=0 ; i--)
       {               
          if( sk.size() == 0)  v.push_back(-1) ;
           
           else if(sk.size() >0 && sk.top() > h[i] ) v.push_back(sk.top() ) ;
           
           else if( sk.size() > 0 && sk.top() <= h[i] )
           {
               while( sk.size() > 0 && sk.top() <= h[i] ) sk.pop() ;
               
               if( sk.size() == 0) v.push_back(-1) ;
               else 
                   v.push_back(sk.top() ) ;
           }
           
           sk.push( h[i]);
       }
        
        
        reverse( v.begin() , v.end() ) ;
        
        vector<int>ans ;
        for( int i= 0 ; i<n ; i++) ans.push_back( v[i]) ;
        return ans;     
        
    }
};