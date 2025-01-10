class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxarea=0;
        stack<int>st; // isme sirf index honge...naki values
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                int ele=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxarea=max(maxarea,heights[ele]*(nse-pse-1));
            }
             st.push(i);
            
            
        }
        // agar kuch element bach gay toh mtlb unn element ko touch nai kiya
        while(!st.empty())
            {
                int ele=st.top();
                st.pop();
                int nse=n;
                int pse=st.empty()?-1:st.top();
                maxarea=max(maxarea,heights[ele]*(nse-pse-1));
            }
         return maxarea;
    }
   
};

/*
ISKO SOLVE KRNA EK FORMUAL HAI JOKI CURRENT ELEMENT * (NEXTSMALLER-PREVIOUSMALLER-1) TOH YE FIND KRNE KE LIYE HUM STACK KA USE KRENGE
JISME HAR ELEMENT KO VISIT KRENGE OR USKE CORRESPONDIG USKA NSE AND PSE NIKALENGE OR WO HUM KESE NIKALENGE KI JESE 3 MILA PUSH KRDO PHIR
TABTAK KRTE RAHO JAB TAK USE CHOTTA NAI MILTA JESE MILA WESE WO INDEX HAMARA NSE OR PSE HUM CHECK KRENGE AGR STACK KHALI TOH -1 WRNA TOP ELE
OR PHIR AGAR SARE ELEMENT CHECK KRNE KE BAAD KUC BACH GAY TOH ALAG SE EK WHILE LOOP CHALYNGE..OR US CASE ME HUMARE PASS NSE NAI HOGA TO IMAGINARY
INDEX LENGE JOKI N...

TC O(N)+O(N) DID WIHTOUT PRECOMPUTATION
SC O(N)
*/

/*
### Code ka Logic (Hinglish me):

1. **Setup aur Traversal:**  
   - Ek stack banaya jo sirf **indices** store karega, values nahi.  
   - Heights array ko left se right traverse karte hain (`i = 0 to n-1`).  

2. **Jab current height chhoti ho:**  
   - Agar stack ka top element ki height (`heights[st.top()]`) current height (`heights[i]`) se badi hai, toh:  
     - **Element pop karo:** Stack ka top index nikal lo (uska rectangle end hota hai).  
     - **NSE aur PSE dhoondo:**  
       - NSE (Next Smaller Element): Current index `i`.  
       - PSE (Previous Smaller Element): Agar stack empty ho, toh `-1`, warna stack ka top index.  
     - Area calculate karo aur `maxarea` ko update karo.  

3. **Traversal ke baad remaining elements:**  
   - Agar stack me kuch indices bache hain, toh unka rectangle calculate karo as:  
     - NSE = array ka end (`n`).  
     - PSE = stack ka top (ya `-1` agar empty).  
   - Area calculate karo aur `maxarea` update karo.  

4. **Final Output:**  
   - Sabse bada rectangle area return karo.

   Stack ka Use Kyu?

Stack use karte hain Next Smaller Element (NSE) aur Previous Smaller Element (PSE) ko efficiently find karne ke liye.
NSE aur PSE ke bina rectangle ka width nikalna difficult hota hai.
Traversal me kya kar rahe hain?

Array ko traverse karte waqt, har index ke liye dekhte hain:
Agar current height, stack ke top ki height se chhoti hai, toh iska matlab stack ke top height ka rectangle ab khatam ho gaya hai.
Us rectangle ke liye NSE (current index) aur PSE (stack ka top ya -1) ko use karke width calculate karte hain.
Remaining Elements ko Process Kyu Karna?

Jab array traverse karna complete ho jaata hai, toh stack ke elements ke liye NSE nahi mila hoga.
Inka NSE array ke end tak maana jaata hai (n).
In remaining elements ke liye bhi rectangle ka area calculate karna zaroori hai, kyunki ye bhi histogram ka part hain.
Area Calculation Kyu Zaroori hai?

Area ka formula:
Area
=
Height
×
(
NSE
−
PSE
−
1
)
Area=Height×(NSE−PSE−1)
Yeh rectangle ka width aur height ka product deta hai.
Maximum rectangle area update karte hain, kyunki hume sabse bada rectangle dhoondhna hai.
Return Kya Kar Rahe Hain?

Sabse bada area (maxarea) return karte hain, jo pura histogram me largest rectangle ka size batata hai.
*/
