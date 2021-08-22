class Solution {
public:
    int calculate(string s)
    {
        //https://www.youtube.com/watch?v=HUfUzA9Ekgo
        
       // s = -312 + -1 -( -3+ 1+ (-8 - -1) -1) + -2
            
        int sum  = 0 ;
        int sign = 1;
        stack<int>sk ;
        
         for( int i= 0 ; i<s.size() ; i++)
         {
             char c= s[i] ;
             
             if( isdigit(c) )
             {
                 int val = 0 ;
                 while( i<s.size() && isdigit(s[i]) )
                 {
                     val = val*10 + (s[i]-'0') ;
                     i++;
                 }
                 i-- ;
                 val = val*sign ;
                 sum = sum + val ;
                 sign = 1;
             }
             else if( c == '(')
             {
                 sk.push(sum) ;
                 sk.push(sign) ;
                 sum = 0; 
                 sign = 1;
             }
             else if( c == ')')
             {
                 sum = sum*sk.top() ; sk.pop() ;
                 sum = sum + sk.top() ;  sk.pop() ;
             }
             else if( c== '-')
             {
                 sign = sign*-1 ;
             }
         }
        
            return sum;
    }
};