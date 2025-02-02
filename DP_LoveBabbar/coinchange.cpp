class Solution {
public:
    int solvemem(vector<int>& coins, int amount,vector<int>&dp)
    {
        if(amount==0)
        {
            return 0;
        }
        if(amount<0)
        {
            return INT_MAX;
        }
        if(dp[amount]!=-1)
        {
            return dp[amount];
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            int ans=solvemem(coins,amount-coins[i],dp);
            if(ans!=INT_MAX)
            {
                mini=min(mini,1+ans);
            }
        }
        dp[amount]=mini;
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        
        int ans=solvemem(coins,amount,dp);
        if(ans == INT_MAX) return -1;
        return ans;
        
    }
};
