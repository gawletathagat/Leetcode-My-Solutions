class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        // 3Sol n2, nlogn , n
        //n2 = find all subarray max element
        //    nlogn - priority_queue
//         priority_queue<pair<int, int>>pq ; // number , index
//         vector<int>ans;
        
//         if( k ==0) return ans;
        
//         for( int i=0 ; i<nums.size() ; i++)
//         {
//             while( !pq.empty() && pq.top().second <= i-k )
//             {
//                 pq.pop();
//             }
            
//             pq.push({nums[i] , i}) ;
            
//             if( i>= k-1)
//                 ans.push_back(pq.top().first) ;
//         }
        
//         return ans;
        
        //O(n) - using deque
        
       deque<int> dq ; // index only
        
        vector<int>ans ;
        
        if (k == 0) return ans;
        for( int i=0 ; i<nums.size() ;i++)
        {
            while( !dq.empty() && dq.front() <= i-k ) dq.pop_front() ;
            
            while( !dq.empty() && nums[dq.back()] <= nums[i] ) dq.pop_back(); 
               
            dq.push_back(i);
                if( i>= k-1) ans.push_back(nums[dq.front()] );
        }
        
        return ans;
        
        
    }
};