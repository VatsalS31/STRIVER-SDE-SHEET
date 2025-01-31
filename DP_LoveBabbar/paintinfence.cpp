class Solution {
  public:
  int solvemem(int n,int k,vector<int>&dp)
  {
      if(n==1)
        {
            return k;
        }
        if(n==2)
        {
            return (k+k*(k-1));
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        dp[n]=(solvemem(n-2,k,dp)+solvemem(n-1,k,dp))*(k-1);
        return dp[n];
      
  }
    int countWays(int n, int k) {
        vector<int>dp(n+1,-1);
        return solvemem(n,k,dp);
        
        
        
    }
};


int solvetab(int n,int k)
  {
      vector<int>dp(n+1,0);
      dp[1]=k;
      dp[2]=k+k*(k-1);
      
      for(int i=3;i<=n;i++)
      {
          dp[i]=(dp[i-2]+dp[i-1])*(k-1);
      }
      return dp[n];
  }


/*

ISME HUMNE PATTERN DHUNDA...RECURSIVELY DRY RUN KRNE PAR HUME FORMULA YE MILA...F(N)=(F(N-2)+F(N-1))*(K-1)...PHIR ISKO DP ME CONVERT KIYA
Is problem mein hume `n` posts ko `k` colors se is tarah paint karna hai ki koi bhi 2 se zyada consecutive posts same color ke na ho. 
Humne pehle recursion se pattern dhoondha aur dekha ki har post ke liye do choices hoti hain—ya toh last post ko different color se paint karein ya phir last do posts ko same color se paint karein.
Isse ek recurrence relation aata hai: `F(n) = (F(n-1) + F(n-2)) * (k-1)`.
Pehle base cases handle karein—jab `n=1` ho toh `k` ways hote hain, aur jab `n=2` ho toh `k + k*(k-1)` ways hote hain. 
Recursion ka optimization karne ke liye humne DP (memoization + tabulation) ka use kiya, jisme hum `dp` array store karke repeated calculations avoid karte hain.
Tabulation approach space-efficient hai kyunki hum sirf `dp[i-1]` aur `dp[i-2]` ka use kar rahe hain, jo overall `O(n)` time complexity ke saath problem efficiently solve karta hai.

*/
