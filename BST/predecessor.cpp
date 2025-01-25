/* This is the Node class definition

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int data) {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};
*/

Node* findPredecessor(Node* root, Node* p) {
    // add your logic here
	Node*pred=NULL;
	Node*curr=root;
	while(curr)
	{
		if(curr->data < p->data)
		{
			pred=curr;
			curr=curr->right;
		}
		else
		{
			curr=curr->left;
		}
	}
	return pred;
	
}

/*
HUM TREE TRAVERSE KREGE ISME AGAR CURRENT ELEMENT P SE CHOTA HO TOH ISKA MTLB HUME APNA PREDECESSOR MILGYA ABH HUM USE MAXIIZE KRNA HAI
TOH JAB TAK PRED NAI MILTA HUM LEFT JYNGE JESE MILA WESE RIGHT ME JATE JYNGE...

*/
