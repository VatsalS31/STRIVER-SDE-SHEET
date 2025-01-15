class Solution {
  public:
  vector<vector<int>>ans;
  vector<int>path;
  void getpath(Node* node)
  {
      if(node==nullptr) return;
      path.push_back(node->data);
      
      if(node->left==NULL and node->right==NULL)ans.push_back(path);
      else{
          getpath(node->left);
          getpath(node->right);
      }
      path.pop_back();
  }
    vector<vector<int>> Paths(Node* root) {
        if(root==nullptr) return ans;
        getpath(root);
        return ans;
       
    }
};

/*
ISME HUM ROOT SE LEAF TAK TRAVESE KR RE OR JESE RIGHT,LEFT BOTH NULL ISKA MALTB EK PATH MILGYA TOH ADD KRDENGE WRNS RECURSIVELY LEFT,RIGHT
TRAVERSE KREGE..

TC O(N)
SC O(H)
*/
