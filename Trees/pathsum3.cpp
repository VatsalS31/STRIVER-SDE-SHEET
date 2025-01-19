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
    int ans=0;
    void path(TreeNode*root,long long sum){
        if(!root) return;

        if(sum==root->val){
            ans++;
        }
        path(root->left,sum-root->val);
        path(root->right,sum-root->val);
    }
    int pathSum(TreeNode* root, long long targetSum) {
        if(root)
        {
            path(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return ans;
        
    }
};

/*
ISME ME HAR NODE PAR GAY RECURSIVELY AND FIND KIYA KI WAHA SE KOI PATH AA SKTA KYA TARGET SUM KE BARA BAR..AUR WO HUM ESE KREGE KI HAR 
NODE KO TARGETSUM SE MINUS KREGE OR AGLA NODE CHECK KREGE KI US KE BARA BAR HAI KI NAI AUR WO HUM TAB TAK KREGE JABTAK SUM 0 NA HOJYA ..
AGR SUM 0 TOH PTH EXSIST WRNA NAI...
*/
