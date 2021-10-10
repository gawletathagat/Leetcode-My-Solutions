// Maintain a decreasing vector
// for eg: [9,8,1,0,1,9,4,0,4,1] -> [9,8,1,0,0,0,0,0,0,0]
// Now for every index find the farthest index which is less than equal to curr
// element...since the array is sorted in dec order we can apply binary search
class Solution {
public:
    int findele(int high,vector<int>&arr,int ele){
        int low=0; 
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<=ele)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
    int maxWidthRamp(vector<int>& arr) {
        vector<int>v(arr.size());
        v[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            v[i]=min(v[i-1],arr[i]);
        }
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int idx=findele(i-1,v,arr[i]);
            if(idx!=-1)
                ans=max(ans,i-idx);
        }
        return ans;
    }
};