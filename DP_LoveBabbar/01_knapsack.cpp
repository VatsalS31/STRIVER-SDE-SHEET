class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int rec(int capacity, vector<int> &val, vector<int> &wt,int idx,vector<vector<int>>&dp)
    {
        int n=val.size();
        if(idx==n)
        {
            
            
                return 0;
            
        }
        if(dp[idx][capacity]!=-1)
        {
            return dp[idx][capacity];
        }
        
        
        int inc=0;
        if(wt[idx]<=capacity)
        {
            inc=val[idx]+rec(capacity-wt[idx],val,wt,idx+1,dp);
        }
        int exc=0+rec(capacity,val,wt,idx+1,dp);
        dp[idx][capacity]=max(inc,exc);
        return dp[idx][capacity];
    }
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int idx=val.size();
        vector<vector<int>>dp(idx+1,vector<int>(capacity+1,-1));
        return rec(capacity,val,wt,0,dp);
       
    }
};

/*
INCLUDE EXCLUDE KIYA OR HAR INCLUDE PAR CHECK KIYA KI CURRENT WEIGHT BADA NA HAO CAPACITY SE OR AGR TRUE HAI TOH INCLUDE KRKE BAKI RECURSIVELY
DEKHLIYA OR EXCLUDE ME SIMPLE CALL KREGE WITH NO CHANGE IN CAPACITY ONLY IDX++....KRGE..OR PHIR MAX LENGE INC OR EXC KA...


*/
