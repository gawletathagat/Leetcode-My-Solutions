class Solution {
public:
    
    char parent[501];
    void makeParent( int n)
    {
        for( int i=0 ; i<26 ; i++)
            parent[i] = i ;
    }
    
    char findParent( char x)
    {
        if( x == parent[x] ) return x ;
        return findParent(parent[x] ); 
        
    }
    
    bool equationsPossible(vector<string>& equation)
    {
        //Is it really a graph Q ?
        // Yes because every == means there is a connection between the nodes 
        // if Parent( a ) != Parent( b) and == then we make a link between them 
        // if Parnet( a) == Parnet(b) and != then this link should not be there so False
        
        
        // Step-1 , Make self Parent
        int n = equation.size() ;
        makeParent(n ) ;
        
        for( int i = 0 ; i<n ; i++)
        {
            if( equation[i][1] == '=' )
            {
                char x = equation[i][0];
                char y = equation[i][3] ;
                
                x = findParent(x-'a') ;
                y = findParent(y-'a') ;
                
                if( x!= y) parent[x] = y ;
                // char x = findParent(equation[i][0]-'a');
                // char y = findParent(equation[i][3]-'a');
                // if (x != y)
                //     parent[y] = x;
            }
        }
        
        for( int i= 0 ; i<n ; i++)
        {
            if( equation[i][1] == '!')
            {
                char x = equation[i][0] ;
                char y = equation[i][3] ;
                
                x = findParent(x-'a') ;
                y = findParent(y-'a') ;
                
                if( x== y) return false;
                // char x = findParent(equation[i][0]-'a');
                // char y = findParent(equation[i][3]-'a');
                // if (x == y)
                //     return false;
            }
        }
        
        return true;
    }
};