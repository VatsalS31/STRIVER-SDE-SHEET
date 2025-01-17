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
        if(root==NULL || root==p || root==q)
        {
            return root;// kuch nai hai ya phir sir ek element hai p poch gay ya q poch gay toh wo return krdege
        }

        TreeNode* leftpart= lowestCommonAncestor(root->left,p,q);
        TreeNode* rightpart= lowestCommonAncestor(root->right,p,q);
        
        if(leftpart==NULL)
        {
            return rightpart;
        }
        else if(rightpart==NULL)
        {
            return leftpart;
        }
        else
        {
            return root;
        }

        
    }
};

/*
TARVERSE KREGE JO DONO NODE KA LOWEST MEET UP NODE HOGA WO LCA HOGA...TOH HUM LEFT TARVERSE KREGE OR RIGHT TRAVERSE KREGE..AND JAHA SE NULL MILA
USKE OPP WALI VALUE RETURN KREGE...OR JIS NODE PE LEFT OR RIGHT DONO NULL NAI HAI MTLB KUCH VALUES ARAI HAI DONO SIDE SE MTLB WAHI LCA HAI!!

TC O(N)
SC O(N) AUXIALLRY STACK SPACE
*/
