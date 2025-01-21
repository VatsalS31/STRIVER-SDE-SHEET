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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int start,int end,int& idx)
    {
        if(start>end)
        {
            return NULL;
        }
        int rootval=preorder[idx];
        int i=start;
        for(;i<=end;i++)
        {
            if(inorder[i]==rootval)
            {
                break;
            }
            
        }
        idx++;
        TreeNode* root=new TreeNode(rootval);
        root->left=solve(preorder,inorder,start,i-1,idx);
        root->right=solve(preorder,inorder,i+1,end,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int idx=0;
        return solve(preorder,inorder,0,n-1,idx);
        
        
    }
};

/*
ISME HUM PREORDER SE ROOT KINKALENEG OR INORDER ARRAY ME DHUND KAR USKE LEFT OR RIGHT NKALENGE RECURSIVELY AND INORDER ME AGR ROOT i HAI 
TOH LEFT START SE i-1 TAK HOGA AND RIGHT i+1 SE END TAK HOGA OR USKE ROOT ME STORE KRTE JYNGE OR ROOT RETURN KRDENGE...

*/
