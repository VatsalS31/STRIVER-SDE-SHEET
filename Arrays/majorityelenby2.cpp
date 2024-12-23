class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second>n/2)
            {
                return it.first;
            }
        }
        return -1;
    }
};

// BETTER UPROACH YAHI KI MAP ME SARE ELEMENTS DALO OR JISKI FREQUENCY N/2 SE JYADA HOGI WO ELEMENT RETURN KRDENA
// TC O(NLOGN)+O(N)
//SC O(N)

// OPTIMAL SOLUTION

// MOORE'S VOTING ALGORITHM
/*
 TC O(N)
 SC O(1)
Phase 1: Find a Candidate

Use a counter (cnt) and a candidate (el).
Traverse the array:
If cnt == 0: Set el = nums[i] and cnt = 1.
If nums[i] == el: Increment cnt.
Else: Decrement cnt.
This leaves the majority element as the candidate if one exists.
Phase 2: Verify the Candidate

Count occurrences of the candidate (el).
If it appears more than 
𝑛
/
2
n/2, return it. Otherwise, return -1.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int el;
        for(int i=0;i<n;i++)
        {
            if(cnt==0)
            {
                cnt=1;
                el=nums[i];
            }
            else if(nums[i]==el)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }

        }
        int cnt1=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==el)
            {
                cnt1++;
            }
            if(cnt1>n/2)
            {
                return el;
            }
        }
        return -1;
        
    }
};
