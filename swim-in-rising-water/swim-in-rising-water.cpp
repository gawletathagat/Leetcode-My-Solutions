class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int> > > pq;
        
        vector<vector<int>> vis(n+1, vector<int>(n, false));
        int dx[]={1,0,0,-1};
        int dy[]={0,1,-1,0};
        
        pq.push({grid[0][0], 0,0});
        vis[0][0]=true;
        
        while(!pq.empty()){
            int curx = pq.top()[1];
            int cury=pq.top()[2];
            int mn = pq.top()[0];
            pq.pop();
            
            if(curx == n-1 && cury ==n-1) return mn;
            
            for(int i=0;i<4;i++){
                int nx = curx+dx[i];
                int ny = cury+dy[i];
                
                if(nx<0 || ny<0 || ny>=n || nx>=n) continue;
                
                if(vis[nx][ny]==true) continue;
                
                vis[nx][ny]=true;
                pq.push({max(grid[nx][ny],mn),nx,ny});
            }
        }
        return -1;
    }
};