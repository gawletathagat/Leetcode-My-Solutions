class NumMatrix {

vector<vector<int>> numatrix;
public:
NumMatrix(vector<vector<int>>& matrix) {
numatrix = matrix;

    int m = numatrix.size();
    int n = numatrix[0].size();
    
    for(int i = 1; i < m; i++)
        numatrix[i][0] += numatrix[i - 1][0];
    
    for(int i = 1; i < n; i++)
        numatrix[0][i] += numatrix[0][i - 1];
    
    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            numatrix[i][j] += numatrix[i - 1][j] + numatrix[i][j - 1] - numatrix[i - 1][j - 1];
}

int sumRegion(int row1, int col1, int row2, int col2) {
    
    int ans = numatrix[row2][col2];
    if(row1 > 0 && col1 > 0)
        ans += numatrix[row1 - 1][col1 - 1];
    if(row1 > 0)
        ans -= numatrix[row1 - 1][col2];
    if(col1 > 0)
        ans -= numatrix[row2][col1 - 1];
    
    return ans;
}
};

