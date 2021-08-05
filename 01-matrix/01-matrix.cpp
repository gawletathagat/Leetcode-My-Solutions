class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
       // dfs show the TLE , but BFS got acceped
        
          int n = mat.size() ;
        int m = mat[0].size() ;
        
       queue<pair<int, int>> q;
        vector<vector<int>>res( n, vector<int>(m, INT_MAX))  ;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 0) {
				q.push({i, j});
				res[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		if (a + 1 < n and b < m) {
			if (mat[a + 1][b] > 0) {
				if (res[a + 1][b] > res[a][b] + 1) {
					res[a + 1][b] = res[a][b] + 1;
					q.push({a + 1, b});

				}

			}
		}
		if (a >= 0 and b + 1 < m) {
			if (mat[a][b + 1] > 0) {
				if (res[a][b + 1] > res[a][b] + 1) {
					res[a][b + 1] = res[a][b] + 1;
					q.push({a, b + 1});

				}

			}

		}
		if (a - 1  >= 0 and b < m) {
			if (mat[a - 1][b] > 0) {
				if (res[a - 1][b] > res[a][b] + 1) {
					res[a - 1][b] = res[a][b] + 1;
					q.push({a - 1, b});
				}
			}
		}
		if (a >= 0 and b - 1 >= 0) {
			if (mat[a][b - 1] > 0) {
				if (res[a][b - 1] > res[a][b] + 1) {
					res[a][b - 1] = res[a][b] + 1;
					q.push({a, b - 1});

				}
			}
		}


	}
	return res;

}
};