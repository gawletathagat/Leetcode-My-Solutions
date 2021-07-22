class Solution {
public:
    
    string sol( string str)
    {
        unordered_map<char, int> hmap;
        int i = 1;
        string order = "";
        
        for(auto ch : str)
        {
            if(hmap.find(ch) == hmap.end())
                hmap[ch] = i++;
            
            order += to_string(hmap[ch]);
        }
        return order;
    }
    
    bool isIsomorphic(string s, string t) 
    {
        return sol( s) == sol(t) ;
        
    }
};