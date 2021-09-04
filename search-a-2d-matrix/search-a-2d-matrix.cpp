class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
         if(matrix.size()==1 && matrix[0].size()==1 && target != matrix[0][0] ) return false;
     
        if(matrix.size()==1 && matrix[0].size()==1 && target == matrix[0][0] ) return true;
     
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        for( int i= 0 ; i<n ; i++)
        {
            int l = 0 , r = m-1;
            while( l<=r)
            {
                int mid = l+ (r-l)/2 ;
                
                if( matrix[i][mid] == target ) return true;
                else if( matrix[i][mid] > target) r = mid-1;
                else 
                    l = mid + 1;
            }
        }
        return false;
    }
};