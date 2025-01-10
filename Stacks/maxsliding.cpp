//BRUTE FORCE
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<=n-k;i++)
        {
            int maxi=nums[i];
            for(int j=i;j<=i+k-1;j++)
            {
                maxi=max(maxi,nums[j]);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};
/*
PURE ARRAY ME TRAVERSE KRO OR HAR INDIVIDUAL WINDOW KO PKDO OR USME USKA MAXI NIKALO OR VECTOR ME ADD KRDO
TC O(N-K)*K
SC O(N-K) // WAHI VECTOR KI
*/

// OPTIMAL SOLUTION

/*
DEQUE USE KRENGE JISME ADD OR REMOVE DONO HO SKE ISME HUM 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<n;i++)
        {
            if(!dq.empty() && dq.front()==i-k)dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};

Input aur Variables Setup:

nums array diya hai aur k window size hai.
Ek deque (double-ended queue) banayi gayi hai jo indices store karegi, not values.
ans vector banaya jo har window ka maximum element store karega.
Traversal (Window Process karna):

Array ke har element (i = 0 se n-1) ko process karte hain:
Old Elements Remove Karo:
Agar dq ka front index i-k ke barabar hai (window ke bahar), toh usse dq.pop_front() karke remove kar dete hain.
Smaller Elements Remove Karo:
Jab tak dq ke back me aise elements hain jo nums[dq.back()] < nums[i], unhe remove karte hain (dq.pop_back()), kyunki woh current window ka maximum nahi ban sakte.
Current Index Add Karo:
Current index i ko dq ke back me push karte hain (dq.push_back(i)).
Window ka Maximum Element:

Jab i >= k-1 ho (window ready ho chuki hai), tab dq.front() index ke corresponding value ko ans me add karte hain, kyunki dq.front() hamesha current window ka maximum element hota hai.
Output:

Traversal ke baad ans vector return karte hain, jo har sliding window ka maximum element store karta hai.
Kyun Kar Rahe Hain (Logic Behind Steps):
Deque ka Use Kyu?

Deque hume efficiently maximum element track karne me help karta hai (O(1) me access).
Front pe window ka maximum hamesha hota hai, aur back me naye elements add hote hain.
Old Elements Remove Karna:

Deque ke front pe agar aise elements hain jo current window ke bahar hain (i-k se chhote), toh unhe remove karte hain, kyunki unka koi kaam nahi.
Smaller Elements Remove Karna:

Jo elements current element (nums[i]) se chhote hain, unhe deque ke back se remove karte hain.
Current element potential maximum ban sakta hai, toh chhote elements ko rakhna bekar hai.
Current Window ka Maximum:

Har window ka maximum dq.front() pe hota hai, toh usse answer me dalte hain
*/
