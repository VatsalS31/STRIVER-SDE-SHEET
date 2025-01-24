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
    bool is_bst(TreeNode *root , long mini , long maxi)
    {
        if(root == NULL)
            return true;
        
        if(root->val >= maxi || root->val <= mini)
            return false;

        return is_bst(root->left , mini , root->val) && is_bst(root->right , root->val , maxi);
    }

    bool isValidBST(TreeNode* root) 
    {
        long mini = LONG_MIN;
        long maxi = LONG_MAX;
        return is_bst(root , mini , maxi);   
    }
};

/*
ISME HUM SAME MINI,MAXI RANGE WALA CONCPT LAGYNGE AGR LEFT ME GAY TOH INT_MIN SE ROOT KI VAL TAK HONA CHAIYE OR AGRA RIGHT ME GAY TOH ROOT KI VAL SE INT_MAX TAK HONA CHAIYE..
OR PURA TREE HUM RECURSIVELY TRAVERSE KREGE...
*/
