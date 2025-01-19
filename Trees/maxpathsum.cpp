/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int path(TreeNode*root,int&maxi)
    {
        if(root==NULL)return 0;
     int left=max(0,path(root->left,maxi));//if i got -ve sum ill not consider i will return 0 
    int right=max(0,path(root->right,maxi));//if i got -ve sum ill not consider i will return 0
        maxi=max(maxi,root->val+left+right);// yahi logi har node par backtrack krne ka or wapas check krne ka
        return (root->val)+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        path(root,maxi);
        return maxi;
        
    }
};

/*
HAR NODE PR GAY RECURSIVELY OR WAHA SE CHEK KIYA KE USKE MAX LEFT KITNA HAI AND MAX RIGHT KITNE HAI OR CURR+LEFT+RIGHT KO MAXI ME UPDATE KIYA
AND ESA HAR NODE SE KRA..OR MAXI WALI LINE ISLYE LIKHI KYUKI AGR EK NODE SE LEFT GAY OR MAXIMUM NAI MILA TOH BACKTRACK KRKE DUSRE NODE GAY..
ESA KRTE GAI..UNTILL WE GOT MAX NODE!!

Algorithm / Intuition:  
Binary tree ka diameter nikalne ke liye, hum har node ko ek potential **"Curving Point"** samajh sakte hain. Is curving point par hum left subtree, right subtree aur us node ke value ka sum karke maximum path ka sum nikalte hain.  

Hum recursively tree ko traverse karte hain, har node ko ek turning point ke roop mein consider karte hain aur ek reference variable mein maximum value store karte hain. Recursive function aise likha jaata hai ki dono possibilities ko consider kare:  

1. **Jab current node turning point ho:**  
   Is case mein, hum left aur right subtree ke maximum path sum ka sum karte hain aur current node ke value ko bhi add karte hain.  

2. **Jab current node turning point na ho:**  
   Is case mein, hum sirf left ya right subtree ka maximum sum consider karte hain. Dono me se jo bada ho, wahi return karte hain.  

### Base Case:  
Jab current node null ho (yaani path ka end ya leaf node ho), to maximum path sum **0** return karte hain.  

---

### Recursive Function:  
1. **Left aur right subtree ka maximum path sum** calculate karne ke liye recursive call karte hain.  
2. **Jab current node turning point ho:** Maximum Path Sum = Left Subtree ka Maximum + Right Subtree ka Maximum + Current Node ki Value  
3. **Overall maximum (maxi)** ko update karte hain agar naya sum pehle wale maximum se zyada ho.  
4. Sirf ek branch ka maximum sum (left ya right, jo bada ho) return karte hain aur usme current node ka value add karte hain.  

---

### Algorithm:  
1. **Step 1:** Ek variable **maxi** initialize karo, jo minimum possible integer value ho (negative infinity). Ye ensure karega ki sabse pehle valid path sum update ho jaye.  
2. **Step 2:** Recursive function `findMaxPathSum` ko root node ke saath call karo aur `maxi` ko reference mein pass karo.  
3. **Step 3:** Base case: Agar current node null ho, to 0 return karo.  
4. **Step 4:** Left aur right subtree ka maximum path sum recursion se calculate karo.  
5. **Step 5:** Turning point consider karte hue maxi ko update karo:  
   \[
   \text{Max Path Sum} = \text{Left Subtree Max} + \text{Right Subtree Max} + \text{Current Node Value}
   \]
6. **Step 6:** Sirf ek branch ka maximum sum return karo (left ya right subtree ka sum, jo bada ho) aur current node ka value add karo.  

---

**Negative Leaf Nodes ko Consider Karna:**  
Agar tree mein koi negative leaf nodes ho, to bhi algorithm unhe handle karega, kyunki recursion base case mein negative nodes ki value ko effectively handle karte hain.


*/
