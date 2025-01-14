class Solution {
  public:
    vector <int> topView(Node *root) {
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
           if(mp.find(line)==mp.end()) mp[line]=node->data;
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



/*Logic Explanation in Hinglish:
Goal: Ye code binary tree ka top view find karta hai. Top view mein har vertical line ke jo nodes dikhayi dete hain, unko show kiya jata hai (jo sabse upar hoti hain).

Step-by-Step Approach:
Data Structures:

map<int, int> mp:
Map mein vertical line (x-coordinate) aur us vertical ke top-most node ka data store karte hain.
queue<pair<Node*, int>> q:
Queue mein nodes ko store karte hain BFS (Breadth-First Search) ke liye. Queue ka har element ek pair hai jisme:
Node* node: Node ka pointer.
int line: Vertical line ka number (x-coordinate).
Initial Setup:

Agar root node NULL hai, toh empty vector return karte hain.
Agar root node NULL nahi hai, toh queue mein root node ko add karte hain, aur uska vertical line 0 set karte hain (root ka x-coordinate 0 hota hai).
BFS Traversal:

BFS shuru karte hain:
Pop karte hain node ko queue se.
Vertical line ko line variable mein store karte hain.
Agar vertical line ka entry map mein nahi hai, toh us vertical line ko top view ke liye add karte hain (mp[line] = node->data).
Ye check ensure karta hai ki har vertical line ka sirf top-most node hi map mein store ho (agar us line ka node pehle se map mein hai, toh naye node ko ignore karenge).
Agar node ka left child hai, toh usse queue mein add karte hain aur vertical line ko line-1 karte hain (left ka x-coordinate ek kam hota hai).
Agar node ka right child hai, toh usse queue mein add karte hain aur vertical line ko line+1 karte hain (right ka x-coordinate ek zyada hota hai).
Result Construction:

Jab BFS complete ho jata hai, map ke andar har vertical line ke top-most node ki value store ho chuki hoti hai.
Map ko iterate karte hain aur har vertical line ke node ko vector ans mein add karte hain.
Return Result:

Finally, top view ka result ans vector mein hoga, jisme top-most nodes ki values honge.
*/
