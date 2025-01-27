/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)return "";
        queue<TreeNode*>q;
        string s="";
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL)s.append("#,");
            else s.append(to_string(node->val)+',');
            if(node!=NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")node->left=NULL;
            else{
                TreeNode* leftn=new TreeNode(stoi(str));
                node->left=leftn;
                q.push(leftn);
            }

            getline(s,str,',');
            if(str=="#")node->right=NULL;
            else{
                TreeNode* rightn=new TreeNode(stoi(str));
                node->right=rightn;
                q.push(rightn);
            }
        }
        return root;
    }
};

/*
HUM KOI TRAVERSAL KE MADAD SE USE SERIALIZE KREGE OR STRING ME APPEND KREGE OR RETURN KREGE AND USSI STRING IS BUILD TREE KRKE TREE CONSTRUCT 
KREGE...BAS...BUT HAI ITNA ASAN NAI HAI...

TC O(N)
SC O(N)

### Logic aur Approach ka Explanation (Hinglish mein):

Yeh code ek **binary tree** ko serialize aur deserialize karne ke liye likha gaya hai. 

---

#### **Serialization: Tree ko String mein Convert Karna**

1. **Kaise kaam karta hai:**
   - Tree ko **level-order traversal (BFS)** ke through traverse kiya jaata hai.
   - Ek **queue** use hoti hai jo har level ke nodes ko process karta hai.
   - Agar koi node `NULL` hai, toh uske jagah `#` string mein add ki jaati hai. Ye null ka indication deta hai.
   - Har node ke baad ek `,` lagaya jaata hai taki string ko parse karte waqt easily separate kar sakein.

2. **Code Walkthrough:**
   - Agar root `NULL` hai, toh directly empty string return hoti hai.
   - Root node ko queue mein push karte hain.
   - Jab tak queue empty nahi hoti:
     - Queue ke front node ko pop karte hain aur:
       - Agar node `NULL` hai, toh `#` string mein add karte hain.
       - Agar node `NULL` nahi hai, toh node ki value string mein add karte hain aur uske left aur right child ko queue mein push karte hain (chahe woh `NULL` hi kyu na ho).

3. **Output Example:**
   - Agar tree hai:
     ```
          1
         / \
        2   3
           / \
          4   5
     ```
   - Serialized string banegi: `1,2,3,#,#,4,5,#,#,#,#,`

---

#### **Deserialization: String ko Wapas Tree mein Convert Karna**

1. **Kaise kaam karta hai:**
   - String ko ek **queue** ke through process karte hain.
   - Root node ke liye sabse pehli value li jaati hai aur ek tree ka construction shuru hota hai.
   - Har node ke liye:
     - Left aur right children ko string se extract karte hain.
     - Agar child `#` hai, iska matlab woh node `NULL` hai.
     - Agar valid value hai, toh ek new node create hoti hai aur queue mein push hoti hai.

2. **Code Walkthrough:**
   - Agar input string empty hai, toh `NULL` return karte hain.
   - Pehli value ko root node banate hain aur queue mein push karte hain.
   - Jab tak queue empty nahi hoti:
     - Queue ke front node ko process karte hain.
     - Left aur right child ke liye string se values lete hain:
       - Agar value `#` hai, toh child `NULL` hai.
       - Agar valid value hai, toh ek nayi node create karte hain aur queue mein add karte hain.

3. **Output Example:**
   - Input string: `1,2,3,#,#,4,5,#,#,#,#,`
   - Reconstructed tree:
     ```
          1
         / \
        2   3
           / \
          4   5
     ```

---

### **Important Points:**
1. **Serialization mein Level-Order Traversal:**
   - BFS ka use karke tree ko ek linear format mein convert karte hain.
   - `#` ka use null nodes ko represent karne ke liye hota hai.

2. **Deserialization mein Queue ka Role:**
   - Queue ka use BFS ke logic ke basis par reconstructed tree ko maintain karne ke liye hota hai.
   - String se sequentially values leke tree ka structure wapas banate hain.

3. **Edge Cases Handle Kiya Gaya Hai:**
   - Empty tree ke liye empty string return hoti hai.
   - Agar string mein `#` aaye, toh `NULL` nodes ko handle kiya jaata hai.

---

Yeh code **efficient hai** aur binary tree ke structure ko accurately preserve karta hai. BFS approach ensure karti hai ki serialization aur deserialization dono linear time complexity mein ho (`O(n)`), jahaan `n` tree ke nodes ki count hai.

*/

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
