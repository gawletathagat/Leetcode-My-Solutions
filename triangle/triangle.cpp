class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) 
    {
         int i,j;
        int n=v.size();
        if(n==0)
            return 0;
        for(i=n-2;i>=0;i--)
        {
            for(j=0;j<v[i].size();j++)
            {
                v[i][j] = v[i][j] +  min (  v[i+1][j] ,  v[i+1][j+1] );               
            }
        }
        
        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<v[i].size(); j++) cout<<v[i][j]<<" ";
            cout<<endl;
        }
        return v[0][0];
    }
};