class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int , vector<int>> hashMap;
        for(int i = 0 ; i < groupSizes.size() ; ++i)
        {
            hashMap[groupSizes[i]].push_back(i);
        }
        
        vector<vector<int>> result;
        
        for(auto it : hashMap)
        {
            vector<int> group;
            for(int i = 0 ; i < it.second.size() ; ++i)
            {
                group.push_back(it.second[i]);
                if((i + 1)%it.first == 0)
                {
                    result.push_back(group);
                    group.clear();
                }
            }
        }
        return result;
    }
};