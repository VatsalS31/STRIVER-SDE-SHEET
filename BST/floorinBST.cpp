class Solution{

public:
    int floor(Node* root, int x) {
        // Code here
        int f=-1;
        int key=x;
        while(root)
        {
            if(root->data==key)
            {
                f=root->data;
                return f;
            }
            if(key>root->data)
            {
                f=root->data;
                root=root->right;
            }
            else
            {
                root=root->left;
            }
        }
        return f;
    }
};

/*
FLOOR MATLBA US ELEMENT X SE BADI VALUE NIKALO JO X SE CHOTI HAI MATLAM MANLO X=5  OR NODE HAMARE PAAS 3,4 HAI TOH 5 SE CHOTI WESE BADII
TOH 4 ANS HOGA..TOH JESE ROOT KI VAL KEY KE EQL HOGAI TOH STORE KRKE RETURN KRDEGE ..OR AGR BADI MILGAI TOH STORE KRKE OR BADI NIKALNE 
RIGHT ME CHLEJYGE...WRNA LEFT ME JAT RYGE..JAB TAK KREGE TAB TAK NULL NA HOJAY...
*/
