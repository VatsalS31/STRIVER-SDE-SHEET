/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw = curr -> next;
        while(curr != NULL) {
                forw = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = forw;
        }
        return prev;
}

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)//l1 0 hai toh l2 add hoke l2 he dega
        {
            return l2;
        }
        if(l2==NULL)// l2 0 hai toh l1 add hoke l1 itself he dega
        {
            return l1;
        }

        //reverse

        // l1=reverse(l1);
        // l2=reverse(l2);
        ListNode* anshead=NULL;
        ListNode* anstail=NULL;
        int carry=0;
        while(l1!=NULL && l2!=NULL)
        {
            int sum=carry+l1->val+l2->val;
            int digit=sum%10;
            carry=sum/10;

            ListNode* newnode = new ListNode(digit);//creating the node with digit

            if(anshead==NULL)//1st node hai insert krne ko
            {
                anshead=newnode;
                anstail=newnode;
            }
            else //already node hai
            {
                anstail->next=newnode;
                anstail=newnode;
            }

            //lets add next element
            l1=l1->next;
            l2=l2->next;
        }

        // l1 me elements present hai l2 ka vishay khtm hai
        while(l1!=NULL)
        {
            int sum=carry+l1->val;
            int digit=sum%10;
            carry=sum/10;
            ListNode* newnode=new ListNode(digit);
            anstail->next=newnode;
            anstail=newnode;
            l1=l1->next;
        }
         // l2 me elements present hai l1 ka vishay khtm hai

        while(l2!=NULL)
        {
            int sum=carry+l2->val;
            int digit=sum%10;
            carry=sum/10;
            ListNode* newnode=new ListNode(digit);
            anstail->next=newnode;
            anstail=newnode;
            l2=l2->next;
        }

        //add krne par last me carry bach gya toh like 999 + 999 ---> 1 as carry bachega
        while(carry!=0)
        {
            int sum=carry;
            int digit=sum%10;
            carry=sum/10;
            ListNode* newnode=new ListNode(digit);
            anstail->next=newnode;
            anstail=newnode;
        }

       // anshead=reverse(anshead);
        return anshead;
        
    }
};
/*
ISME EACH NODE KI VALUES KO ADD KREGE OR EK NEW NODE ME DALKE NEW LL BANAYNGE AND HUM YE LL1 AND LL2 NULL TAK POCH JAY TAB TAK KREGE AND 
REMAINING CARRY BHI ADD KREGE LAST ME OR AT END REVERSE KRDEGE LL KO..
TC O(MAX(L1,L2))
sc O(N)  NEW LL 
*/
