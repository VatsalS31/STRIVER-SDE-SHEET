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
int height(TreeNode*root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    
    return 1 + max(height(root->left), height(root->right));
} 
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
       
        int lh = height(root->left);
        int rh = height(root->right);

        if(abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        {
            return true;
        }
       return false;
        
    }
    
};

/*
IN THIS HUM PEHLE HEIGHT NIKALEGE OR LEFT HEIGHT,RIGHT HEIGHT NIKALEGE AND DONO KA ABSOULUTE DIFF AGR <=1 HAI OR THE NODE WHICH RETURN FALSE
FROM ANY SIDE EITHER LEFT OR RIGHT IT MEANS IT IS NOT A BALANCE BT..

### Hinglish Explanation of Code:

Yeh code ek **binary tree** ka balance check karta hai. Ek **balanced binary tree** tab hota hai jab har node ke **left subtree** aur **right subtree** ki height ka difference **1 ya usse kam** ho. Saath hi, har subtree khud bhi balanced hona chahiye.

---

### Code ka Logic Step-by-Step:

#### 1. **`height` Function**:
   - **Purpose**: Kisi bhi node ka height nikalta hai.
   - **Logic**:
     - Agar `root` NULL hai (tree khali hai), toh height `0` return karo.
     - Agar tree khali nahi hai:
       - Left subtree ki height aur right subtree ki height ko nikalte hain.
       - In dono ka maximum leke `+1` karte hain (current node ka contribution).
   - **Example**:
     - Tree:
       ```
           1
          / \
         2   3
       ```
       - Left subtree (root = 2) ka height: `1`
       - Right subtree (root = 3) ka height: `1`
       - Root node (1) ka height: `1 + max(1, 1) = 2`

#### 2. **`isBalanced` Function**:
   - **Purpose**: Pura tree balanced hai ya nahi, yeh check karta hai.
   - **Logic**:
     1. **Base Case**:
        - Agar `root` NULL hai, toh tree balanced hai (`true` return karo).
     2. **Left aur Right Subtree ki Height**:
        - `height` function ka use karke left aur right subtree ki height nikalte hain.
     3. **Difference Check**:
        - `abs(lh - rh)`:
          - Agar height difference `1 ya usse kam` hai aur dono subtrees (`isBalanced(root->left)` aur `isBalanced(root->right)`) khud bhi balanced hain, toh tree balanced hai.
     4. **Return False**:
        - Agar kisi bhi condition ke liye imbalance milta hai, toh `false` return karo.

---

### Example Execution:

#### Input Tree:
```
       1
      / \
     2   3
    / \
   4   5
```

#### Execution:

1. **Root = 1**:
   - Left subtree ka height (`lh`) = `2`
   - Right subtree ka height (`rh`) = `1`
   - `abs(2 - 1) = 1` (valid)

2. **Left Subtree (Root = 2)**:
   - Left subtree ka height (`lh`) = `1`
   - Right subtree ka height (`rh`) = `1`
   - `abs(1 - 1) = 0` (valid)

3. **Right Subtree (Root = 3)**:
   - Left aur right subtree khali hain, toh height = `0`.
   - Balanced hai.

#### Result:
- Tree balanced hai, so return `true`.

---

### Key Points:
1. Har node ke left aur right subtree ki height ka difference `<= 1` hona chahiye.
2. Subtrees khud bhi balanced hone chahiye.
3. Recursive calls ka use karke har node ko check karte hain.

TC O(N)
SC O(N) AUXI SPACE
*/
