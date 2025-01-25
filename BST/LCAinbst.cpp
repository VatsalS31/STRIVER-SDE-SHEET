/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)
        {
            return nullptr;
        }
        int curr=root->val;
        if(curr<p->val && curr<q->val)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        if(curr>p->val && curr>q->val)
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
        
    }
};

/*
HUM TREE TRAVERSE KREGE RECURSIVLEY AND CHECK KREGE KI CURR VALUE (ROOT KA VALUE HUR RECURSIVE CALL KE BAAD NEW ROOT) AGRA CHOTTA HAI
P,Q SE (ELEMENT JISKE BICH KA LCA NIKAL NA HAI) MATLAB P,Q BADE HAI TOH KAHE NA KAHI RIGHT ME ANS HOGA TOH RIGHT ME CALL KREGE
SAME VICE VERSA LEFT ME BHI KREGE ,,OR AT END JAHA YE FALSE HUA MATLAB NODE NA BADI HAI NA CHOTI WAHA  RUK JYGA WO ROOT RETURN KRDEGE

*/
