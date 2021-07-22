class Solution {
public:
    int binarySearch(vector<int> & arr, vector<int> & temp, int end, int val){
        int start = 0;
        int len = end;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[temp[mid]] < val)
                start = mid+1;
            else
                end = mid-1;
        }
        return start;
        
    }
    
    int lis(vector<int> & arr){
        vector<int> temp(arr.size(), 0);
        int len = 0;
        for(int i=1;i<arr.size();i++){
            if(arr[i] > arr[temp[len]]){
                len++;
                temp[len] = i;
            }
            else if(arr[i] < arr[temp[0]])
                temp[0] = i;
            else{
                int index = binarySearch(arr, temp, len, arr[i]);
                temp[index] = i;
            }
        }
        return len+1;
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() == 0 || envelopes.size() == 1)
            return envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto & lhs, const auto & rhs){
            return lhs[0] == rhs[0] ? lhs[1] > rhs[1]: lhs[0] < rhs[0];
        });
        vector<int> arr;
        for(int i=0;i<envelopes.size();i++)
            arr.push_back(envelopes[i][1]);
        return lis(arr);
        
    }
};