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
bool sym(TreeNode* l,TreeNode*r)
{
    if(l==NULL || r==NULL) return r==l;
    if(l->val!=r->val) return false;

    return sym(l->left,r->right) && sym(l->right,r->left);
}
    bool isSymmetric(TreeNode* root) {
        return root==NULL || sym(root->left,root->right);
        
    }
};

/*
ME EK TREE KE LEFT SIDE ME OR RIGTH SIDE ME SIMULTANEOUSLY TAVERSE KRUGA...THAT IS LEFT SIDE HU TOH HUM NLR(NODE LEFT RIGHT) AND RIGHT SIDE
HAI TOH NRL(NODE RIGHT LEFT) THIS IS MAIN KEY OF SYMMETRY AGAR YE HAI TOH TRUE ELSE FALSE..

TC O(N)
SC O(N) AUXILARY...
*/
