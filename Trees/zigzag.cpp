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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr)return ans;

        bool flag=true;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>level(size);//level wise val dalenge
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();

                int ind=(flag)?i:(size-i-1);////agar falg true hai mtlb L-->R wrna R---->L,,toh \\true hoga toh i idx me dldo wrna reverse krke piche dldo
                level[ind]=node->val;
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            flag=!flag;//mark krdiya..ek level hote he..
            ans.push_back(level);
        }
        return ans;
        
    }
};

/*
LEVEL TRAVERSE KRUGA OR EK FLAG RKHUGA JO DIRECTION MAINTAIN KREGA JOKI AGAR FLAG=TRUE TOH LEFT TO RIGHT WRNA RIGHT TO LEFT OR IS TARA 
QUEUE ME DALTE JYNGE OR DIRECTION DEKHEKE INSERT KRTE JYGE..
TC  O(N)
SC O(N)
*/
