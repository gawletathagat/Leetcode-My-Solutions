class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&b,vector<vector<bool>>&vis,int n,int m){
        if(i<0||j<0||i>=n||j>=m||vis[i][j]||b[i][j]=='X'){
            return;
        }
        vis[i][j]=true;
        dfs(i+1,j,b,vis,n,m);
        dfs(i-1,j,b,vis,n,m);
        dfs(i,j+1,b,vis,n,m);
        dfs(i,j-1,b,vis,n,m);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<m;i++){
           dfs(0,i,board,vis,n,m);
        }
         for(int i=0;i<n;i++){
           dfs(i,0,board,vis,n,m);
        }
        
         for(int i=0;i<m;i++){
           dfs(n-1,i,board,vis,n,m);
        }
        
         for(int i=0;i<n;i++){
           dfs(i,m-1,board,vis,n,m);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};