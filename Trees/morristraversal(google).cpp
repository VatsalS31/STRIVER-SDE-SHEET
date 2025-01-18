                            
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to perform iterative Morris
    // inorder traversal of a binary tree
    vector<int> getInorder(TreeNode* root) {
        // Vector to store the
        // inorder traversal result
        vector<int> inorder;
        // Pointer to the current node,
        // starting from the root
        TreeNode* cur = root;
        
        // Loop until the current
        // node is not NULL
        while (cur != NULL) {
            // If the current node's
            // left child is NULL
            if (cur->left == NULL) {
                // Add the value of the current
                // node to the inorder vector
                inorder.push_back(cur->val);
                // Move to the right child
                cur = cur->right;
            } else {
                // If the left child is not NULL,
                // find the predecessor (rightmost node
                // in the left subtree)
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                
                // If the predecessor's right child
                // is NULL, establish a temporary link
                // and move to the left child
                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    // If the predecessor's right child
                    // is already linked, remove the link,
                    // add current node to inorder vector,
                    // and move to the right child
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        
        // Return the inorder
        // traversal result
        return inorder;
    }
};

/*
Morris Traversal ka logic samajhne ke liye, socho ki hum ek binary tree ka inorder traversal karna chahte hain bina recursion ya stack ke use kiye, aur hum temporary pointers ka use karke yeh kaam karte hain. Iska main focus hai space complexity ko O(1) banana, jo traditional approaches (recursion/stack) mein O(h) hoti hai (h = height of tree).

Hinglish mein step-by-step logic:
Current node par focus karte hain:

Ek pointer cur ko root node par set karte hain aur traversal start karte hain.
Left subtree check karte hain:

Agar cur->left NULL hai, iska matlab hai ki left subtree nahi hai.
cur ki value ko result list (inorder traversal) mein daal do.
cur ko right child par move kar do (cur = cur->right).
Predecessor dhundhte hain:

Agar cur->left NULL nahi hai, iska matlab hai ki left subtree exist karta hai.
Tab hum cur ke left subtree ke andar jaakar predecessor node dhundhte hain (predecessor = left subtree ka rightmost node).
Predecessor ke right child ko handle karte hain:

Agar predecessor ka right NULL hai, iska matlab hai ki pehli baar is node par aaye hain:
Ek temporary link banate hain predecessor->right = cur (current node ko predecessor ke right se link karte hain).
cur ko left child par move karte hain (cur = cur->left) taaki hum left subtree process kar sakein.
Agar predecessor ka right cur ke barabar hai, iska matlab hai ki hum already left subtree traverse kar chuke hain:
Temporary link todte hain (predecessor->right = NULL).
cur ki value result mein daal do aur right child par move kar jao (cur = cur->right).
Traversal complete hone tak loop repeat karte hain:

Jab tak cur NULL nahi ho jata, upar ke steps ko repeat karte hain.
*/
