class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        // 2 solutions DP , Greedy 
        
        //m-1 dp
        vector<bool>visited(nums.size(), false) ;
        
        visited[0] = true;
        
        for( int i= 1 ; i<nums.size() ; i++)
        {
            for( int j= i-1 ; j>=0 ; j--)
            {
                if(visited[j] == true && j+ nums[j] >= i )
                {
                    visited[i] = true;
                   // visited[j+ nums[j]] = true;
                    break;
                }
            }
        }
        
         return visited[nums.size()-1] ;
        
        
        
    }
};