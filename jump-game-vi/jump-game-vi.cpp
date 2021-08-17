class Solution {
public:
    
   int maxResult(vector<int>& nums, int k)
  {
    int n = nums.size();
    priority_queue<pair<int, int>> maxHeap;
    maxHeap.push({nums[0], 0});
    
    for(int i=1;i<n;i++)
    {
        while(i-maxHeap.top().second > k) maxHeap.pop();
        
        int curr_sum = maxHeap.top().first;
        
        int idx = maxHeap.top().second;
        
        maxHeap.push({curr_sum+nums[i], i});            
    }
    
    while(maxHeap.top().second != n-1)maxHeap.pop();
       
    return maxHeap.top().first;
  }

};