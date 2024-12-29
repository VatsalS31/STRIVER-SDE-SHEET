/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
         ListNode* fast=head;
        if(head==NULL)
        {
            return false;
        }

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            return true;
        }
        return false;
        
        
    }
};

/*
SLOW OR FAST POINTER LENEGE SLOW 1 KDMM CHELHGA OR FAST 2KDM...JAB TAK FAST NULL NAI POCHTA TAB TAK LOOP CHLYGE OR AGR..SLOW==FAST HOGYA 
YANI INTERSECT HOGAY TOH TRUE RETURN KRDENGE WRNA NO LOOP (FALSE)
*/
