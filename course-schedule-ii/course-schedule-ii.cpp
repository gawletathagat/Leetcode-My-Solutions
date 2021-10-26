class Solution {
public:
    int dfs(int u,vector<vector<int>> &adj,vector<int> &vis,vector<int> &ans){
        vis[u]=1;
        for(auto j: adj[u]){
            if(vis[j]==1){
                return 1;
            }
            else if(vis[j]==0){
                if(dfs(j,adj,vis,ans))return 1;
            }
        }
        ans.push_back(u);
        vis[u]=2;
        return 0;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
                vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> vis(numCourses,0);
        vector<int> ans,an;
        for(int i=0;i<numCourses;i++){
            if(vis[i])continue;
            if(dfs(i,adj,vis,ans))return {};
        }
       reverse(ans.begin(),ans.end());
        return ans;
    }
};