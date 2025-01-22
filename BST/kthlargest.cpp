class Solution {
  public:
  void inorder(Node*root,vector<int>&ans)
  {
      if(root==NULL)
      {
          return;
      }
      inorder(root->left,ans);
      ans.push_back(root->data);
      inorder(root->right,ans);
  }

    int kthLargest(Node *root, int k) {
        vector<int>sol;
       
        inorder(root,sol);
         int n =sol.size();
        return sol[n-k];
       
    }
};

/*
ISME INORDER KIYA OR ARRAY ME STORE KRDIYA AND (N-K)th ELEMENT RETURN KRDIYA!!
*/
