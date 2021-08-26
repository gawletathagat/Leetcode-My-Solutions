class Solution {
public:
    
    int dist[12][12];
    int dp[12][4096];
    int cnt;
    set<pair<int,int>> st;
    
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n=graph.size();
        int siz=pow(2,n);
        cnt=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<siz;j++)
            {
                dp[i][j]=-1;
            }
        }
        
        
        for(int j=0;j<n;j++)
        {
            bool vis[n];
            memset(vis,false,sizeof(vis));
            
            queue<int> q;
            int lev[n];
            lev[j]=0;
            vis[j]=true;
            q.push(j);
            
            while(!q.empty())
            {
                int s=q.front();
                q.pop();
                for(int i=0;i<(int)graph[s].size();i++)
                {
                    int curr=graph[s][i];
                    if(!vis[curr])
                    {
                        lev[curr]=lev[s]+1;
                        vis[curr]=true;
                        q.push(curr);
                    }
                }
            }
            
            for(int i=0;i<n;i++)
            {
                dist[j][i]=lev[i];
            }
            
        }
        
        
        
        int ans=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            ans=min(ans,travellingSalesman((1<<i),i,siz-1,n));
        }
        cout<<cnt;
        
        return ans;
    }
    
    int travellingSalesman(int mask,int s,int target,int n)
    {
        //st.insert({s,mask});
        cnt++;
        
        if(dp[s][mask]!=-1)
        {
            return dp[s][mask];
        }
        
        int curr=mask|(1<<s);
        
        if(curr==target)
        {
            return 0;
        }
        
        int minn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if((mask&(1<<i))==0)
            {
                minn=min(minn,dist[s][i]+travellingSalesman(curr,i,target,n));
            }
        }
        
        dp[s][mask]=minn;
        
        return dp[s][mask];
    }
    
};