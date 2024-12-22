class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
             sum+=nums[i];
             if(sum>maxi)
            {
                maxi=sum;
            }
            if(sum<0)
            {
                sum=0;
            }
            
           
        }
        return maxi;
        
    }
};

/*
BRUTE FORCE CAN BE USING NESTED FOR LOOP GETTING ALL THE SUB ARRAYS ANFD IN THAT USING ANOTHER FOR LOOP FRO i->j AND TAKING SUM
AND IF ITS MAXIMUM THEN PRINT

TC O(N^3)

BETTER UPROACH CAN BE REMOVING SUM FOR LOOP THAT US WO K WALA LOOP SIMULTANEOUSLY IN J LOOP ADDING THE SUM AND CHECKING FOR MAXIMUM
TC O(N^2)

OPTIMAL IS KADANES ALGO THAT IS ADDING ELEMENT TO SUM IF SU  IS -VE THEN NO POINT TO TAKE FORWARD SO DO SUM=0 AND IF ITS +VE
THEN ADD TO MAXI AND IF AFTER COMING -VE ELEMENT BUT AGAR SUM +VE HAI TOH KOI DIKKAT NAI AAGE BEDENGE HAM OR AT THE END SUM RETURN
TC O(N)

*/
