class Solution {
public:
    
    int calculate(vector<vector<int>>& students, vector<vector<int>>& mentors,int index,int t){
        int sum = 0;
        for(int i=0;i<students[0].size();i++)
            if(students[index][i] == mentors[t][i])
                sum++;
    
        return sum;
    
    }
    
    int dfs(vector<vector<int>>& students, vector<vector<int>>& mentors,vector<bool>& visited,int index){
        if(index >= students.size())
            return 0;
    
        int ans = INT_MIN;
        int m = students.size();
        for(int i=0;i<m;i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                int temp  =  calculate(students,mentors,index,i);
                ans = max(ans,dfs(students,mentors,visited,index+1)+temp);
                visited[i] = false;
            }
        }
        
        return ans;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        vector<bool> visited(m);
        return dfs(students,mentors,visited,0);
    }
};