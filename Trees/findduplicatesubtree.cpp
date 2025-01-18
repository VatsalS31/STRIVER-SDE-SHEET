class Solution {
public:
    vector<TreeNode*> ans;
    unordered_map<string, int> submap;

    string preorder(TreeNode* root) {
        if (!root) return "N"; // Use "N" for null nodes

        // Serialize the subtree rooted at the current node
        string curr = to_string(root->val);
        string l = preorder(root->left);
        string r = preorder(root->right);
        string s = curr + "," + l + "," + r;

        // Check if the serialized subtree is already in the map
        if (submap[s] == 1) {
            ans.push_back(root);
        }

        // Update the count of the current subtree in the map
        submap[s]++;

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preorder(root);
        return ans;
    }
};

/*
WE WILL TRAVERSE WHOLE TREE AND GET THE EMBEDING OF EACH NODE AND STORE IN THE MAP AND IF COUNT =1 IT MEANS WE HAVE ONE AND COUNT =2 THEN WE
WILL STOP TAKING IT ROOT WE WILL CONVERT THE EMBEDDING TO STRING AND MATCH WITH IT IF WE GOT ANY OTHER IT MEANS DUPLICATE SUBTREE HAI OR 
HUM PREORDER SE TREE TRAVERSE KREGE...
*/
