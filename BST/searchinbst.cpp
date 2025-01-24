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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val==val)
        {
            return root;
        }
        if(root->val>val)
        {
            return searchBST(root->left,val);
        }
        return searchBST(root->right,val);
            
        
    }
};

/*
ISME HUM TREE ME TRAVERSE KREGE OR AGR ROOT KA VALUE VAL KI EQUAL HUA TOH RETURN KRDEGE WRNA BST KA CONCEPT LAGYGE..KI AGR ROOT KA VALUE BADA HUA VAL SE TO HAME CHOTA CHAIYE TOH 
LEFT ME CALL KREGE ELSE RIGHT ME CALL KREGE
*/
