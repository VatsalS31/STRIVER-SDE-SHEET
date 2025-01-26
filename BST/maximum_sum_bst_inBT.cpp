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
class info
{
    public:
    int maxi;
    int mini;
    bool isbst;
    int sum;
};
info solve(TreeNode* root,int &ans)
{
    if(root==NULL)
    {
        return {INT_MIN,INT_MAX,true,0};
    }
    info left=solve(root->left,ans);
    info right=solve(root->right,ans);

    info curr;

    curr.sum=left.sum+right.sum+root->val;
    curr.maxi=max(root->val,right.maxi);
    curr.mini=min(root->val,left.mini);

    if(left.isbst && right.isbst && (root->val>left.maxi && root->val <right.mini))
    {
        curr.isbst=true;
    }
    else
    {
        curr.isbst=false;
    }

    if(curr.isbst)
    {
        ans=max(ans,curr.sum);
    }
    return curr;
}
    int maxSumBST(TreeNode* root) {
        int maxsum=0;
        info temp=solve(root,maxsum);
        return maxsum;
        
    }
};


/*
Is code ka logic aur approach samajhne ke liye humein samajhna hoga ki yeh problem kya solve kar rahi hai aur kaise yeh kaam kar rahi hai.

### Problem Statement:
Humein ek binary tree diya gaya hai, aur humein uska **subtree** dhundhna hai jo **Binary Search Tree (BST)** ho aur us subtree ka **maximum sum** return karna hai.

---

### Approach ka Overview:
1. Ek helper class `info` banayi gayi hai jo har node ke liye kuch information rakhegi:
   - `maxi`: subtree ke andar ka sabse bada value.
   - `mini`: subtree ke andar ka sabse chhota value.
   - `isbst`: yeh batata hai ki subtree BST hai ya nahi (true/false).
   - `sum`: subtree ke sabhi nodes ka sum.

2. Ek recursive function `solve` likha gaya hai jo tree ke har node ke liye kaam karega aur `info` return karega.

3. **Base Case:** Agar koi node `NULL` hai, toh uska subtree empty hoga aur wo BST maana jaayega.

4. **Recursive Case:** Har node ke liye:
   - Uske **left subtree** aur **right subtree** se `info` nikalte hain.
   - Current node ka sum aur `maxi`, `mini` calculate karte hain.
   - Check karte hain ki agar:
     - Left aur right subtree BST hain.
     - Aur current node ka value left subtree ke `maxi` se bada hai aur right subtree ke `mini` se chhota hai.
   - Agar yeh sab conditions satisfy hoti hain, toh current node ke saath jo subtree banta hai wo BST hai.
   - BST hone par uska sum `ans` ke saath compare karke maximum update karte hain.

5. Return karte hain overall `ans` jo maximum sum hai kisi BST subtree ka.

---

### Code ka Detailed Explanation:
```cpp
class info
{
    public:
    int maxi;  // Subtree ka maximum value
    int mini;  // Subtree ka minimum value
    bool isbst; // Kya subtree BST hai?
    int sum;   // Subtree ke nodes ka sum
};
```

Yeh class ek helper structure hai jo har node ke liye subtree ki necessary information store karega.

---

#### `solve` Function:
```cpp
info solve(TreeNode* root,int &ans)
{
    if(root==NULL)
    {
        return {INT_MIN,INT_MAX,true,0};
    }
```
- **Base Case:** Agar node `NULL` ho, toh:
  - `maxi` ko `INT_MIN` set karte hain (kyunki koi valid maximum nahi hoga).
  - `mini` ko `INT_MAX` set karte hain.
  - `isbst` ko `true` set karte hain (empty tree BST hota hai).
  - `sum` ko `0` set karte hain.

---

```cpp
    info left=solve(root->left,ans);
    info right=solve(root->right,ans);
```
- Left aur right subtree ke liye recursive call karte hain, aur unka result `info` objects mein store karte hain.

---

```cpp
    info curr;
    curr.sum=left.sum+right.sum+root->val;
    curr.maxi=max(root->val,right.maxi);
    curr.mini=min(root->val,left.mini);
```
- Current node ka:
  - `sum`: Left aur right subtree ke sum aur current node ke value ka total.
  - `maxi`: Current node aur right subtree ka maximum value.
  - `mini`: Current node aur left subtree ka minimum value.

---

```cpp
    if(left.isbst && right.isbst && (root->val > left.maxi && root->val < right.mini))
    {
        curr.isbst=true;
    }
    else
    {
        curr.isbst=false;
    }
```
- Check karte hain ki:
  1. Left aur right subtree BST hain.
  2. Current node ka value left subtree ke maximum se bada hai.
  3. Current node ka value right subtree ke minimum se chhota hai.
- Agar yeh sab true hai, toh current subtree BST hoga (`isbst = true`), warna nahi.

---

```cpp
    if(curr.isbst)
    {
        ans=max(ans,curr.sum);
    }
```
- Agar current subtree BST hai, toh uska sum `ans` ke saath compare karke maximum update karte hain.

---

```cpp
    return curr;
}
```
- Current node ka `info` return karte hain.

---

#### `maxSumBST` Function:
```cpp
int maxSumBST(TreeNode* root) {
    int maxsum=0;
    info temp=solve(root,maxsum);
    return maxsum;
}
```
- Root node se start karke tree ko traverse karte hain.
- Final answer `maxsum` return karte hain, jo maximum sum of BST subtree hoga.

---

### Example to Understand:
#### Input Tree:
```
       1
      / \
     4   3
    /   / \
   2   4   5
```

1. Har node ke liye `solve` function recursively call hoga.
2. Subtree ke `info` calculate hote rahenge.
3. BST conditions ko check karke `ans` ko update karte rahenge.

#### Output:
Maximum sum of BST subtree = 12 (subtree rooted at node `3`).

---

### Complexity:
- **Time Complexity:** \(O(N)\) - Har node ko ek baar traverse karte hain.
- **Space Complexity:** \(O(H)\) - Recursive stack ka space, jaha \(H\) tree ka height hai.

*/
