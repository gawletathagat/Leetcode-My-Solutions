class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) 
    {
       // simple HashMap ;
        int maxi = 0;
        unordered_map<int ,int> mp ;
        
        for( int i= 0 ; i<arr.size() ; i++)
        {
            if( mp.find(arr[i]-diff) == mp.end() ) 
            {
                mp[arr[i]] = 1;
            }
            else 
            {
                mp[arr[i]] = mp[arr[i]-diff] + 1;
            }
            
            maxi = max( maxi , mp[arr[i]] ) ;
        }
        
        return maxi ;
    }
};