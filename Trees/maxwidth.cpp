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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int size = q.size();
            int min = q.front().second;
            int first, last;
            for(int i = 0; i<size; i++) {
                int cur_id = q.front().second - min;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0) first = cur_id;
                if(i == size-1) last = cur_id;
                if(node->left) q.push({node->left, (long long)cur_id*2 + 1});
                if(node->right) q.push({node->right, (long long)cur_id*2 + 2});
            }
            ans = max(ans, last-first+1);
        } 
        return ans;
    }
};

/*
ISME HUM LEVEL ORDER KRKE LAST LEVEL KA MOST LEFT AND MOST RIGHT NODE KA NO. NIKALENGE AND THEN +1..

Code ka Logic Step-by-Step:
Initial Check: Agar root NULL hai, toh return 0 kardo, kyunki tree khali hai aur koi width nahi hogi.

Queue ka Use:

Ek queue banayi gayi hai jisme hum pair rakhte hain:
Node (TreeNode*)
Us node ka index (uske level par).
Yeh index binary tree ke properties ke hisaab se calculate hoga:
Left child ka index = 2 * parent_index + 1
Right child ka index = 2 * parent_index + 2
Level-Wise Traversal:

Queue ka use karke tree ko level order traversal karte hain (ek level ke sab nodes ko process karte hain).
Har level ke liye:
First node ka index (first) aur last node ka index (last) ko calculate karte hain.
In dono indexes ka difference (last - first + 1) hume current level ka width dega.
Is width ko maximum width (ans) ke saath update karte hain.
Index Normalization:

Har level ke liye, nodes ke indexes ko normalize karte hain taaki large values ka issue na ho.
Normalize ka matlab:
Sabhi nodes ke indexes ko current level ke leftmost index (min) se subtract karna.
Queue Update:

Har node ke liye:
Agar node ka left child hai, toh usko queue mein push karte hain aur index (2 * cur_id + 1) assign karte hain.
Agar node ka right child hai, toh usko queue mein push karte hain aur index (2 * cur_id + 2) assign karte hain.
Result:

Har level ka width calculate karne ke baad, sabse maximum width (ans) ko return karte hain.

*/
