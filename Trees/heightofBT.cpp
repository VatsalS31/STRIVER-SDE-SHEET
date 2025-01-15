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
    int maxDepth(TreeNode* root) {

       if (root == NULL)
    {
        return 0;
    }

    int height_left = maxDepth(root->left);

    int height_right = maxDepth(root->right);
    int ans = max(height_left, height_right) + 1;
    return ans;
}
};

/*
LEFT HEIGHT AND RIGHT HEIGHT FIND MAX AND +1..
*/
