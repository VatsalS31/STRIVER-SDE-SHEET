class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,-1);
        int l=0;
        int right=0;
        int len=0;
        int n=s.length();
        while(right<n)
        {
            if(mp[s[right]]!=-1)// matlab element exsist krta hai
            {
                l=max(mp[s[right]]+1,l);
            }
            mp[s[right]]=right;
            len=max(len,right-l+1);
            right++;
        }
        return len;
        
    }
};

// BRUTE FORCE TOH YAHI HAI KI SARE SUBARRAY GENERATE KRO KADANES ALGO SE OR DEKHO KONSI BADI HAI

/*
OPTIMAL IS KI MAP BANAO ELEMENT OR USKE INDEX KE SAATH OR HAR ELEMENT CHECK KRO OR DEKHO MAP ME HAI KI NAI AGR HAI ISKA MATLAB WO PEHLE 
AA CHUKA HAI TPH REPEATING HORA HAI WRNA MAP ME ADD KRO OR LEN BADAO OR AAGE BADHOO
TC O(N)
SC O(N)
*/
