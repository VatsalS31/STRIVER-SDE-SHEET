class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int nge[nums1.size()];
        stack<int> st;
        map<int, int> mp;
        for(int i = nums2.size()-1; i>=0; i--) {
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            if(st.empty()) mp[nums2[i]] = -1;
            else mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans(nums1.size());
        for(int i = 0; i<nums1.size(); i++) {
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};

/*
WE STARTED FROM BACK OF THE ARRAY AND KEEP CALCULATING THE NEXT GREATER AND SIMULATANEOSULY STORING ITS ELEMENT AND CORRESPONDING NEXT GREATER
ELEMENT AND THE WE TRAVESE THE MAP AND PRINT THE NUMS1 'S NGE ELEMENT FROM MAP

TC O(2N) FOR LOOP OR WHILE LOOP 
SC O(N)+O(N) VECTOR AND STACK
*/
