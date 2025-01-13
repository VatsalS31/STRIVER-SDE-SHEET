class Solution {
  public:
  void rec(Node*root,int level,vector<int>&res)
  {
      if(root==NULL)
      {
          return;
      }
      if(res.size()==level)
      {
          res.push_back(root->data);
      }
      rec(root->left,level+1,res);
      rec(root->right,level+1,res);
  }
    vector<int> leftView(Node *root) {
        vector<int>ans;
        rec(root,0,ans);
        return ans;
        // code here
    }
};

/*
RECURSIVELY LEFT SE CHALU KRO KYUKI JO PEHLE DEKHEGA WO HUM ADD KREGE...
TC O(N)
SC O(H) HEIGHT OF  A TREE
*/
