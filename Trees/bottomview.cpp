class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        if(root==NULL) return ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node* node=it.first;
            int line =it.second;
            mp[line]=node->data;
            if(node->left!=NULL)
            {
                q.push({node->left,line-1});
            }
            if(node->right!=NULL)
            {
                q.push({node->right,line+1});
            }
        }
        
        for(auto i:mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};

/*
ISME HUM SAME VERTICAL ORDER KI TARA KRENGE JESE -2 -1 0 1 2 JESI VERTICAL LINE HOGI US HISSAB SE ELEMENT STORE KRENGE QUE ME LEVEL WISE TRAVERSE
KREGE AGAR LEFT ME GAY TOH LEFT VALUE OR LINE -1 AND RIGHT ME GAY TOH RIGHT VALUE LEFT +1..

Maksad:

Ye code ek binary tree ke bottom view ko find karta hai. Bottom view mein har vertical line ke neeche wale node ki values hoti hain, matlab jo nodes sabse neeche dikhte hain (horizontal level ke basis pe).
Data Structures:

map<int, int> mp:
Is map ka use hum vertical level (x-coordinate) ko track karne ke liye karte hain. Har vertical ke liye, map mein last node ka data (y-coordinate ke basis pe) store hoga.
queue<pair<Node*, int>> q:
Queue mein BFS (Breadth-First Search) ke liye nodes store karte hain. Queue mein pair hota hai, jisme:
Node* node: Current node ka pointer.
int line: Vertical line ka number (x-coordinate).
Traversal Process:

Pehle root node ko queue mein daalte hain with vertical line 0 (root node ka x-coordinate 0 hota hai).
BFS start karte hain. Har step mein:
Node ko pop karte hain queue se.
Uske corresponding vertical line ko map mein store karte hain (mp[line] = node->data). Ye line ke last node ko store karta hai, jo bottom view mein dikhayi dega.
Agar node ka left child hai, toh usse queue mein daalte hain aur uska vertical line line-1 hota hai (left child ka x-coordinate 1 kam hota hai).
Agar node ka right child hai, toh usse queue mein daalte hain aur uska vertical line line+1 hota hai (right child ka x-coordinate 1 zyada hota hai).
Answer Construction:

Jab BFS complete ho jata hai, toh map<int, int> mp ke andar har vertical line ka last (bottom-most) node stored hota hai.
Final answer ke liye, map ke through iterating karte hain aur har vertical line ke node value ko vector ans mein daalte hain.
Return Answer:

ans vector ko return karte hain, jo bottom view ki values hoti hain.


*/
