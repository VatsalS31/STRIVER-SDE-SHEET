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
    TreeNode* build(int &i,int mini,int maxi,vector<int>&preorder)
    {
        if(i>=preorder.size())
        {
            return NULL;
        }
        TreeNode* root=nullptr;
        if(preorder[i]>mini && preorder[i]<maxi)
        {
            root=new TreeNode(preorder[i++]);
            root->left=build(i,mini,root->val,preorder);
            root->right=build(i,root->val,maxi,preorder);
        }
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini=INT_MIN;
        int maxi=INT_MAX;
        int i=0;
        return build(i,mini,maxi,preorder);

        
    }
};

/*
BRUTE FORCE--
ARRAY ME TRAVERSE KREGE OR HAR EK ELEMENT KE LIYE PURA ARRAY DEKHEGE KIKAHA AYGA..AGR CHOTTA ELEMENT TOH LEFT ME WRNA RIGHT ME...

TC O(N^2)

HUM ARRAY ME ITERATE KRTE WAKT(RECURSIVELY) USKI RANGE SET KRDE DETE HAI USING MINI AND MAXI TAKI PATA CHALA KI AGLA ELEMENT KAHA ANE WALA HAI AGR CHOTA US RANGE ME AGAY TOH LEFT ME
WRNA RIGHT ME..
TC O(N)

s code ka approach yeh hai ki hum ek binary search tree (BST) ko preorder traversal ke input ke basis par construct karte hain. Yahaan step-by-step samajhte hain:

1. Preorder Traversal Samajhna
Preorder traversal mein, sabse pehle root node aata hai, uske baad left subtree aur phir right subtree.
Iska matlab hai ki preorder array ke elements ko agar hum ek-ek karke process karein, toh har element ek naya node banega BST ka, lekin unhe sahi jagah lagana zaruri hai.
2. Function build ka Explanation
build ek recursive function hai jo tree banata hai.

Parameters:

i - Yeh preorder array ka index track karta hai, jo abhi process ho raha hai.
mini - Yeh minimum value hai jo current node ke valid hone ke liye zaruri hai.
maxi - Yeh maximum value hai jo current node ke valid hone ke liye zaruri hai.
preorder - Yeh input array hai jo preorder traversal represent karta hai.
Logic:

Agar i array ke size se bada ho gaya, toh iska matlab koi aur node banane ki zarurat nahi hai, toh NULL return karte hain.
Agar preorder[i] ki value mini aur maxi ke beech mein hai:
Ek nayi node banate hain TreeNode(preorder[i]).
Index i ko badhate hain.
Left Subtree: Is node ke left child ke liye build function ko call karte hain jaha maxi current node ki value hoti hai.
Right Subtree: Is node ke right child ke liye build function ko call karte hain jaha mini current node ki value hoti hai.
3. Function bstFromPreorder ka Explanation
Yeh main function hai jo BST construct karta hai.
mini ko INT_MIN aur maxi ko INT_MAX set karte hain, kyunki initially root ke liye koi restrictions nahi hain.
i = 0 se shuru karte hain, jo preorder ka pehla element hai.
build function ko call karte hain jo pura tree construct kar deta hai aur root node return karta hai.
4. Kaise Kaam Karta Hai?
Preorder traversal ke har element ko recursively process karte hain aur BST ki properties ko maintain karte hain:
Left subtree ke liye value chhoti honi chahiye root se.
Right subtree ke liye value badi honi chahiye root se.
Valid range (mini aur maxi) ko har call ke saath update karte hain.

*/
