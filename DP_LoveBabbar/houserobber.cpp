class Solution {
public:
    int solvemem(vector<int>&nums,int n,vector<int>&dp)
    {
        if(n<0)
        {
            return 0;
        }
        if(n==0)
        {
            return nums[0];
        }

        if(dp[n]!=-1)
        {
            return dp[n];
        }

        int inc=solvemem(nums,n-2,dp)+nums[n];
        int exc=solvemem(nums,n-1,dp);

        dp[n]=max(inc,exc);
        return dp[n];
    }
    int solvetab(vector<int>&nums,int n)
    {
        vector<int>dp(n+1,-1);
        dp[0]=nums[0];
        int temp=0;
        for(int i=1;i<=n;i++)
        {
            if(i-2>=0)
            {
                temp=dp[i-2];
            }
            int inc=temp+nums[i];
            int exc=dp[i-1];

            dp[i]=max(inc,exc);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
       
        return solvetab(nums,n);
        
    }
};

/*
ISME WAHI KREGE AGR ith INDEX LELIYA TOH next wala nai le skte yani adjacent wala nai le skte..i+2 wala he lena hoga..or hum YE RECURSIVELY TAKE NOT TAKE KREGE THAN DP ME KREGE
MEMOZIATIONA AND TABULATION..SE...

*/
