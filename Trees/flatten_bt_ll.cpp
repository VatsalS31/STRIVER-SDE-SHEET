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
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        while(curr)
        {
            if(curr->left)
            {
                TreeNode*pred=curr->left;
                while(pred->right)
                {
                    pred=pred->right;
                }
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=nullptr;


            }
            curr=curr->right;
            

        }
        
    }
};

/*
ISME HUM POINTER KI MADAD SE LINKS KO ADJUST KREGE ...EK CURR POINTER ROOT KO POINT KREGA AND PRED POINTER CURR KE LEFT KO OR HAR CURR KE
PRED KE RIGHT ME JATE RAYNGE OR ...SOME WHAT MORRIS TRAVERSAL JESA LINK KO CHANGE KRKE ANS NIKALENEG ...BUT CATCH YE HAI KI JAB HAUM LINK
BREAK KREGE TOH CONNECTION TUT JYAG TOH HUM USE STORE KREGE AND THEN LINKS KO MOVE KRKE LL ME CONVERT KREGE ...ISME RIGHT LINK HUMARE
LL KE LINK BANEGE OR LEFT JO HAI OW NULL/HEAD PTR....

TC O(N)

*/
