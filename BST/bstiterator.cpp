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
class BSTIterator {
    private:stack<TreeNode*>st;
public:
    BSTIterator(TreeNode* root) {
        pushall(root);
        
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        pushall(temp->right);
        return temp->val;
        
    }
    
    bool hasNext() {
        return !st.empty();
        
    }

    private:
    void pushall(TreeNode* root)
    {
        for(;root!=NULL;st.push(root),root=root->left);
    }
};


/*
ISME HUME 3 CHIZ IMPLEMENT KRNI HAI JOKI HAI NEXT,HASNEXT,BSTITERATOR JO SARE NODE KO ITEREATE KRGA JO HUM STACKK KE MAFA SE USME PUSH KRDEGE
OR NEXT MTLB CURR NODE KA NEXT KYA HAI..OR HASNEXT KA MATLBA KI KOI NEXT HAI (TRUE/FALSE)....TOH HUM STACK ME NODES DALTE JYGE INORDER WISE
OR NEXT ATE HE STACK KA TOP LEGE OR USKA RIGHT CHECK KRGE AGR HAI TOH USKE RIGHT ME JAKE USKE SARE LEFT DAL DEGE AND WRNA USII NODE KA VAL
RETURN KRDEGE...OR HASNEXT MTLB KI STACK ME ELEMENT HAI TOH TRUE ELSE FALSE...

TC O(1)
SC O(H)..HEIGTH OF TREE == H

*/
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
