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
    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>sol;
        inorder(root,sol);
        return sol[k-1];
        
    }
};

/*
DOING INORDER TRAVERSAL I WILL GET ELEMENT IN SORTED ORDER SO DOING THAT I WILL SIMPLY RETURN (K-1)th ELEMENT...
*/
