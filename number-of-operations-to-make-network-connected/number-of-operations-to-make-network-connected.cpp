class Solution {
public:
    vector<int> parent;
    
    int find(int n){
        if(parent[n]==n){
            return n;
        }
        return parent[n] = find(parent[n]);
    }
    
    int makeConnected(int n, vector<vector<int>>& con) {
        int m = con.size();
        parent.resize(n);
        if((n-1)>m){
            return -1;
        }
        
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        
        for(int i=0;i<m;i++){
            int v1 = find(con[i][0]);
            int v2 = find(con[i][1]);
            if(v1!=v2){
                parent[v1] = v2;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                ans++;    
            }
        }
        return ans-1;
    }
};