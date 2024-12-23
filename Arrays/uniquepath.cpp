
//BRUTE FORCE
class Solution {
    public:
    int count(int i,int j,int m,int n)
    {
        if(i==(n-1) && j==(m-1))return 1;//REACHED AT LAST POSSIBLE INDEX
        if(i>=n || j>=m) return 0; // OUT OF BOUND INDEX
        else return count(i+1,j,m,n)+count(i,j+1,m,n); //LEFT TREE COUNT + RIGHT TREE COUNT
    }
public:
    int uniquePaths(int m, int n) {
        return count(0,0,m,n);
        
        
    }
};

/*
GET ALL THE POSSIBLE PATHS AND ADD THE COUNT OF THAT USING RECURSION
TC O(2^N) EXPONENSTIAL
*/
//BETTER UPROACH
/*
 DP SOLUTION
int countPaths(int i,int j,int n,int m,vector<vector<int>> &dp)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
     else return dp[i][j]=countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
       
        //dp[1][1]=1;
       int num=countPaths(0,0,m,n,dp);
        if(m==1&&n==1)
            return num;
        return dp[0][0];
    }
*/

// OPTIMAL SOLUTION (GOOGLE INTERVIEW ***)
/*
COMBINATRICS WALA SOLUTION HAI JISME TOTAL PATHS HOGE M+N-2 OR USME SE M-1(RIGHT PATHS) YA N-1(BOTTOM PATHS) CHOOSE KRNE HOGE THAT IS
M+N-2 
      C
        M-1
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int R=m-1;
        double res=1;
        for(int i=1;i<=R;i++)
        {
            res=res*(N-R+i)/i;
        }
        return (int)res;
    }
};
TC O(M-1) or O(N-1)
SC O(1)
*/

