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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>todo;
        vector<vector<int>>ans;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            TreeNode* node=p.first;//1st node vertical order
            int x=p.second.first; //level
            int y=p.second.second;//level
            nodes[x][y].insert(node->val);
            if(node->left){
                todo.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                todo.push({node->right,{x+1,y+1}});
            }
        }
        for(auto p:nodes){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }

       return ans;
        
    }
};

/*
Vertical Order Traversal:

Code ka main maksad hai ek binary tree ko vertical order me traverse karna aur values ko sorted order me dena.
Data Structures:

map<int, map<int, multiset<int>>> nodes:

Outer map (x): Har vertical level ko represent karta hai.
Inner map (y): Ek vertical ke andar different levels ko store karta hai.
multiset: Same level pe agar multiple nodes hain toh sorted order maintain karta hai.
queue<pair<TreeNode*, pair<int, int>>> todo:

BFS traversal ke liye use hoti hai. Pair me:
TreeNode*: Current node ka pointer.
(x, y): x vertical level aur y horizontal level.
Traversal Process:

Root node ko (0, 0) level pe initialize karke queue me daal dete hain.
BFS ke through har node ko process karte hain:
Current node ka value nodes[x][y] me add hota hai.
Agar left child hai toh usko (x-1, y+1) ke saath queue me daal dete hain.
Agar right child hai toh usko (x+1, y+1) ke saath queue me daal dete hain.
Result Construct Karna:

nodes ko traverse karke har vertical column ka sorted data (multiset) ko ek vector me daalte hain.
Final result ans me har column ka vector add hota hai.
Return Answer:

ans ko return karte hain jo ki ek 2D vector hai.

TC O(NlogN)
SC O(N)
*/
