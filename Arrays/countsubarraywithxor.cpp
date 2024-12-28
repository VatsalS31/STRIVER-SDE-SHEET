// BRUTE FORCE
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int currentXor = 0;
            for (int k = i; k <= j; k++) {
                currentXor = currentXor ^ A[k];
            }
            if (currentXor == B) {
                cnt++;
            }
        }
    }
    return cnt;
}

/*
OPTIMAL SOLUTION
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int xr=0;
    map<int,int>mp;
    mp[xr]++;//{0,1}
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        xr=xr^A[i];
        int x=xr^B;
        cnt+=mp[x];
        mp[xr]++;
    }
    return cnt;
}

JUST KEEP TAKING THE XOR OF EACH ELEMENT AND STORE IN THE MAP AND USING AN FORMULA CHECK THAT WHETHER THAT NO. HAD OCCUR IN THAT ARRAY PREVIOUSLY 
OR NOT...
*/
