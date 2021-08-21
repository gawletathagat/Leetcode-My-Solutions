class Solution {
public:
    
    void dfs( int i, int j , vector<vector<char>>&b)
    {
        if( i<0 || i>=b.size() || j<0 || j>=b[0].size() || b[i][j] == 'V' || b[i][j] =='.') return ;
        
        b[i][j] = 'V' ;
        
        dfs( i+ 1, j , b) ;
        dfs( i-1,  j , b) ;
        dfs( i, j+1, b) ;
        dfs(i ,j-1, b) ;
    }
    
    int countBattleships(vector<vector<char>>& b) 
    {
        // simple dfs
        int count = 0 ;
        for( int i= 0 ;i<b.size() ; i++)
        {
            for( int j= 0 ; j<b[0].size() ; j++)
            {
                if( b[i][j] == 'X')
                {
                    count++;
                    dfs( i, j, b) ;
                }
            }
        }
        
        return count;
        
      
    }
};