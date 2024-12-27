class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int cnt=0;
        int longest=0;
        sort(nums.begin(),nums.end());
        int last=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]-1==last)
            {
                cnt++;
                last=nums[i];
            }
            else if(nums[i]!=last)
            {
                cnt=1;
                last=nums[i];
            }
            longest=max(longest,cnt);
        }
        return longest;

        
    }
};
/*
BETTER APPROACH THIS IS THAT IS SORTING THE ARRAY AND CHECKING EACH ELEMENT THAT IS +1 THEN PREVIOUSOR NOT IF IT IS THEN COUNT++ AND IF NEW
ELEMENT OCCURED THEN REVISE THE COUNT =1 AND NEW ELEMENT AS LAST ELE...
*/

/*
OPTIMAL APPROACH

int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

}

USING THE SET DATA STRUCTURE AND CHECKING THE PREVIOUS ELEMENT IS THERE OR NOT IF ITS THERE THAT MOVE FORWARD ELSE THAT IS THE 1ST ELEMENT
*/
