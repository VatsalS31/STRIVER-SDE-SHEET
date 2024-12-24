//BETTER UPROACH
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int a=nums[i];
            int req=target-a;
            if(mp.find(req)!=mp.end())
            {
                return {mp[req],i};
            }
            mp[a]=i;

        }
        return {-1,-1};

        
    }
};
/*
USE HASHMAP AND STORE THE ELEMENT AND ITS CORRESPONDING INDEX AND CHECK AT EVERY ITERATION THAT CURRENT ELEMENT - TARGET THAT IS ELEMENT IS PRESENT OR NOT
IF YES THEN PRINT INDEX OF THE CORRESPONDING ELEMENTS FROM MAP ELSE RETURN -1
TC O(N*LOGN) IF MAP WORKS IN LOGN
SC O(N)
*/

// OPTIMAL SOLUTION
#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}
/*
SORT THE ARRAY AND USE 2 POINTER FROM START AND END OF ARRAY AND KEEP ADDIGN THE ELEMENTS IF > THAN TARGET MEANS WE WANT CHOTTA ELEMENT SO MOVE END ELSE MOVE START
TC O(N)
SC O(1) OR O(N) IF NEED TO STORE THE INDEXES IF WANTS TO RETURN THE INDEXES
*/
