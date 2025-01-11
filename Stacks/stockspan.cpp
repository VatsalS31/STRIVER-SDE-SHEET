class StockSpanner {
public:
vector<int>ans;
    StockSpanner() {
        
    }
    
    int next(int price) {
        ans.push_back(price);
        int cnt=1;
        for(int i=ans.size()-2;i>=0;i--)
        {
            if(ans[i]<=price)cnt++;
            else break;
        }
        return cnt;

        
    }
};
/*
ISME SIMPLY ELEMENT ADD KRO OR TRAVERSE KRO BACKSIDE ME CHECK KRTE HUI KI CHOTE HAI KI NAI AGR HAI TOH CNT KO BADAO WRNA WAHI RUK JAO
YE BRUTE FORCE APPROACH HAI...O(no of days) and SPACE IS O(no of next call) 
*/

/*

ISME OPTIMAL APPROACH ME HUM STACK ME ELEMENT OR USKA IDX DALENGE OR PGE KA CONCEPT LAGAYNGE THAT IS PREVIOUS GREATER ELEMENT NGE KI TARA HAI
AGR CURRENT ELEMENT KA PGE HAI TOH US PGE SE TO CURR ELEMENT TAK SARE US SPAN ME HOGE..TOH AGR PGE MILGYA TOH USKA IDX HUM CURR ISX SE MINUS KIYA
TOH SPAN MILJATA...

*/
class StockSpanner {
public:
int idx=-1;
stack<pair<int,int>>st;
    StockSpanner() {
        idx=-1;
       // st.clear;
        
    }
    
    int next(int price) {
        int val=price;
        idx=idx+1;
        while(!st.empty() && st.top().first<=val)st.pop();
        int ans=idx-(st.empty()?-1:st.top().second);
        st.push({val,idx});
        return ans;
    }
   
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
