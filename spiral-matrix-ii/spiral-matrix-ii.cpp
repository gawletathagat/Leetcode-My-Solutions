class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        int dir = 0;
        vector<vector<int>>ans(n, vector<int>(n, 0)) ;
        
        int top = 0 , left = 0 , right = n-1, down = n-1 ;
        int number= 1;
        
        while( top<=down && left<= right )
        {
           
            if( dir==0)
            {
                for( int j = top ; j<=right ; j++) ans[top][j] = number++ ;
                top++;
            }
            if( dir== 1)
            {
                for( int i= top ; i<=down ; i++) ans[i][right] = number++;
                right--;
            }
            if( dir== 2)
            {
                 for( int j= right ; j>=left ; j--) ans[down][j] = number++;
                down--;
            }
            if( dir== 3) 
            {
                 for( int i= down ; i>=top ; i--) ans[i][left] = number++;
                left++;
            }
            
           // ans.push_back(v) ;
            
            dir = (dir+ 1)%4 ;
        }
        
        return ans;
        
    }
};