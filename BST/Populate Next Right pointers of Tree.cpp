/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)return NULL;

        Node*curr=root;
        while(curr->left!=NULL){
            Node*temp=curr;
            while(curr!=NULL){
                curr->left->next=curr->right;
                curr->right->next=curr->next==NULL?NULL:curr->next->left;//ye wahi condition left part se right part ke conncection se uske child access kr skte...
                curr=curr->next;
            }
            curr=temp->left;
        }

        return root;
        
        
        
    }
};

/*
ISME HUM TREE TRAVERSE KREGE OR 2 POINTER RAKHEGE EK ROOT KO TRACK KREGA OR EK USKE CHILD KO OR BAKI POINTERS KI MADAD SE POPULATE KRDIYA....ROOT KE LEFT SE NEXT KE THROUGH RIGH GAY
THEN AGR BICH ME CONNECTION NAI HAI MTLB DUSRE PART ME HAI TREE KE TOH PHITR CURR KE PATH SE USKE LEFT JAKE POPULATE KREGE...
*/
