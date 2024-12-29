class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
         sort(s.begin(),s.end());
        int l=0;
        int r=0;
        int cnt=0;

        while(l<s.size() && r<g.size())
        {
            if(g[r]<=s[l])
            {
                cnt++;
                l++;
                r++;
            }
            else if(g[r]>s[l])
            {
                l++;
            }
        }
        return cnt;
        
    }
};

/*
I WILL SORT THE BOTH THE ARRAYS AND I WILL CHECK HOW MANY I CAN GIVE THAT MUCH WILL INCREASE THE COUNT AND MAINLY ME YAHI DEKHUNG KI
KITNE BACHE KO SATISFY KR SKTA...
TC O(NLOGN+MLOGM+M)
*/
