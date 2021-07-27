class Solution {
public:
    
    int solve(vector<int> &nums,int sum,int target,int index)
    {
    
    if(index==nums.size())
    {
        if(target==sum)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }  
        int count=0;
        count+=solve(nums,sum - nums[index],target,index + 1);
        count+=solve(nums,sum + nums[index],target,index + 1);
        
        return count;
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {    
        return solve(nums,0,target,0);
    }
};