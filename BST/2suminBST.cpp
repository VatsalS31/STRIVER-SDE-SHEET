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
    void inorder(TreeNode* root,vector<int>&ans)
    {
        
        if(root==NULL)
        {
            return ;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>sol;
        inorder(root,sol);
        int i=0;
        int j=sol.size()-1;
        while(i<j)
        {
            if(sol[i]+sol[j]==k)
            {
                return true;
            }
            else if(sol[i]+sol[j] > k)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
        
    }
};

/*
INORDER KRKE ARRAY SORT HOJYGA...THEN 2 POINTER SE SUM DEKHUGA KI K KE EQUAL HAI KI NAI...
*/
