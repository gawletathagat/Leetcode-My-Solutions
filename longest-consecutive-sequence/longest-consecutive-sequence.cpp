class Solution {
public:
    
    vector<int>p ;
    void makeP( int n)
    {
        for( int i = 0 ; i<n ; i++)
            p[i] = i;
    }
    
    int findP( int node)
    {
        if( node == p[node]) return p[node] ;
        return p[node]= findP(p[node]) ;
    }
    
    void Union( int node1 , int node2)
    {
        node1 = findP(node1) ;
        node2 = findP( node2) ;
        
        p[node1] = node2 ;
    }
    
    
    int longestConsecutive(vector<int>& nums)
    {
       // to do this Q in O(n ) we can use Disjoint set
        
        int n = nums.size() ;
        p.resize(n) ;
        
        makeP( n) ;
        
        unordered_map<int, int>mp ;
        for( int i = 0 ; i<n ; i++)
        {
            mp[nums[i]] = i;
        }
        
        // for( int i= 0 ; i<nums.size() ; i++)
        // {
//             int index = mp[i].second ;
            
//             if(mp.find(mp[index]+ 1) != mp.end() ) 
//             {
//                 Union( index, mp[index]+ 1) ;
//      }

        for( auto it: mp)
        {  
            int index = it.second;   
            //If next element is present, form a union between these indicies
            if(mp.find(nums[index]+1) != mp.end()) 
            {
                Union(index, mp[nums[index]+1]);
            }
        }
        
        unordered_map<int,int>res_mp;
        int res=0;
        for(int i=0;i<nums.size();i++) 
        {
            //Find of i
            int indx=findP(i);
            
            res_mp[indx]++;
            
            res=max(res, res_mp[indx]);
        }
            
        return res;
    }
};