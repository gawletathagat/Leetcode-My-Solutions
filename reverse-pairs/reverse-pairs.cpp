class Solution {
public:
    
    long long int count ;  
    
      void join(vector<int>& nums, int l, int mid, int r){

        // two pointers;
        int start1 = l, start2 = mid + 1;
          
        while(start1 <= mid && start2 <= r){
            if((long)nums[start1] > (long) 2 * nums[start2]){
                count += (mid - start1 + 1);
                start2++;
            }else{
                start1++;
            }
        }
       // worst case might be nlog(n) 
        sort(nums.begin() + l, nums.begin() + r + 1);
        return;

    }
    
 void mergeSort( vector<int>&nums, int l , int r)
    {
        if( l>=r) return ;
        int mid = (l+ r)/2 ;
        
        mergeSort( nums, l, mid) ;
        mergeSort( nums, mid+ 1, r) ;
        
         join( nums, l, mid, r) ;
        return ;
    }
    
    
     int reversePairs(vector<int>& nums) 
    {
         if(!nums.size())return 0;
        count = 0;
       mergeSort(nums, 0, nums.size()-1) ;
        return count ;
    }
};