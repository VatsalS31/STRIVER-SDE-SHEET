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
            if(it.second>n/3)
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

//OPTIMAL SOLUTION
// BOYERS MOORE'S VOTING ALGORITHM

/*
Phase 1: Identify Candidates
Use two counters (cnt1, cnt2) and two candidate variables (el1, el2), initialized as INT_MIN.

Traverse the array:

If cnt1 == 0 and the current element is not el2, set el1 = v[i] and cnt1 = 1.
Else if cnt2 == 0 and the current element is not el1, set el2 = v[i] and cnt2 = 1.
If the current element matches el1 or el2, increment their respective counters.
Otherwise, decrement both cnt1 and cnt2.
This step narrows down at most two candidates that could potentially appear more than 
𝑛
/
3
n/3 times.

Phase 2: Verify Candidates
Reset cnt1 and cnt2 to 0.
Traverse the array again to count occurrences of el1 and el2.
Check if the counts of el1 or el2 exceed 
𝑛
/
3
n/3:
Add them to the result list (ls).

*/
vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return ls;
}
