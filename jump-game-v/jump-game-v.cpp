class Solution {
public:
    
    vector<int> dp,v;
    int n,mx;

    int ans(int pos)
    {
        if(dp[pos]!=-1)
        {
            return dp[pos];
        }
        
        int an=1;
        for(int i=pos+1;(i<n)&&(i<=(pos+mx));i++)
        {
            if(v[i]>=v[pos])
            {
                break;
            }
            an=max(an,1+ans(i));
            dp[pos]=an;
        }
        
        for(int i=pos-1;(i>=0)&&(i>=(pos-mx));i--)
        {
            if(v[i]>=v[pos])
            {
                break;
            }
            an=max(an,1+ans(i));
            dp[pos]=an;
        }
        return an;
    }
    
    
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        mx=d;
        dp.resize(n,-1);
        v=arr;
        
        int an=0;
        for(int i=0;i<n;i++)
        {
            an=max(an,ans(i));
        }
        return an;
    }
};