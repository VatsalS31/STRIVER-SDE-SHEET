class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int n=prices.size();
        int maxpro=0;
        for(int i=0;i<n;i++)
        {
            int cost=prices[i]-mini;
            maxpro=max(cost,maxpro);
            mini=min(mini,prices[i]);
           
        }
        return maxpro;
        
    }
};

// TC O(N) SC O(1)
// FINDING THE MINIMUM PRICE TO BUY THE STOCK AND MAXIMUM PRICE TO SELL TO MAXIMIZE THE PROFIT 
