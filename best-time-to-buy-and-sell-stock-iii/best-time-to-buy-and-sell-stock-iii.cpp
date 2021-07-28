class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int fb_Profit = INT_MIN , sb_profit = INT_MIN;
            
        int fs_profit = 0, ss_profit = 0;
        
        for(int i=0; i<prices.size(); i++)
        {
            fb_Profit = max(fb_Profit, -prices[i]);
            
            fs_profit = max(fs_profit, fb_Profit+ prices[i]);   // fs is 
            
            sb_profit= max(sb_profit, fs_profit-prices[i]) ;
            
            ss_profit= max(ss_profit, sb_profit+ prices[i]);
        }
        
        return ss_profit;
        
    }
};