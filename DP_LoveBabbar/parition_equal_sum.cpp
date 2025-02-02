class Solution {
public:
    bool rec(vector<int>& arr, double target,int idx,vector<vector<int>>&dp)
  {
     if(target==0)return true;
     if(idx<0)return false;
     if(dp[idx][target]!=-1)
     {
         return dp[idx][target];
     }
     if(arr[idx]<=target)
     {
         if(rec(arr,target-arr[idx],idx-1,dp))
         {
              return dp[idx][target] = true;
         }
     }
     return dp[idx][target]= rec(arr,target,idx-1,dp);
      
     
  }
    bool canPartition(vector<int>& nums) {
        double sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1,-1));
        return rec(nums,sum/2,nums.size()-1,dp);
        
    }
};

/*
ARRAY KA SUM NIKALA AND DIVIDE BY 2 KRDIYA OR PURE ARRAY ESA SUBSET NIKALA JISKA SUM SUM/2 KI BARA BAR HO AGR HUA TOH BY DEFAULT DUSRE SUBSET
KA SUM BHI SUM/2 HE HOGA...TO SUM/2 KRKE SUBSET WALA ALGO LAGA DIYA...OR EK CASE ME  GALTI HOGI JO KI YE HAI KI..AGRA SUM ODD HUA TOH USE CASE
ME TOH EQL DIVIDE HOGA HE AI TOH FALSE ANS...

*/
