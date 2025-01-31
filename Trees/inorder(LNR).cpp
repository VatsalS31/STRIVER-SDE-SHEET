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
// LEFT NODE RIGHT
class Solution {
    public:
    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }


public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>sol;
        inorder(root,sol);
        

        return sol;

        
        
    }
};

/*
RECURSIVEL TRAVERSE KRO LEFT-->ROOT-->RIGHT...THATS IT...
*/
