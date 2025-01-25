int findCeil(Node* root, int input) {
   int ceil=-1;
   while(root)
   {
       if(root->data==input)
       {
           ceil=root->data;
           return ceil;
       }
       if(input>root->data)
       {
           root=root->right;
       }
       else
       {
           ceil=root->data;
           root=root->left;
       }
   }
   return ceil;

/*
ISME AGR ROOT KA DATA BADA HAI MATLAB NICE OR BADA MILSKTA HAI TOH RIGHT ME CHALO...NAITOH CHOT HUA TOH STOR KRKE LEFT ME USSE BADA DHUND
 NE CHLE GAY...
*/
