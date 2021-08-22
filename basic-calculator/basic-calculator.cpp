class Solution {
public:
    int calculate(string s)
    {
        int sum = 0 ;
        int sign = 1;
        
        stack<int>sk  ;
        
        for( int i= 0 ; i<s.size() ; i++)
        {
            char ch = s[i] ;
            
            if( isdigit(ch) )
            {
                int val = 0 ;
                while( i<s.size() && isdigit(s[i]) )
                {
                    val = val*10 + (s[i]- '0') ;
                    i++;
                }
                i--;
                val = val*sign ;
                sum = sum + val ;
                sign = 1;  // reset
            }
            else if( ch == '(' )
            {
                sk.push(sum) ;
                sk.push(sign) ;
                sign =  1 ;
                sum = 0 ;
            }
            else if( ch == ')')
            {
                sum = sum*sk.top() ;  sk.pop() ;
                sum = sum + sk.top() ;  sk.pop() ;
            }
            else if( ch == '-')
            {
                sign = sign*-1;
            }
        }
        return sum;
    }
};